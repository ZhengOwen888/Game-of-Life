#include "game_logic/game.hpp"
#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "game_logic/constants.hpp"
#include "command_manager/config.hpp"

#include <iostream>
#include <vector>
#include <random>

namespace GOL
{
    void Game::RandomizeInit()
    {
        std::uniform_real_distribution prob_dist_{0.f, 1.f};
        int population{};

        for (int col = 0; col < gol_config_.width_; col++)
        {
            for (int row = 0; row < gol_config_.height_; row++)
            {
                double alive_prob = prob_dist_(gen_);

                if (alive_prob <= gol_config_.alive_probability_)
                {
                    init_gen_[CalculateIndex(col, row)] = {col, row, 0, CellState::Alive};
                    population++;
                }
                else
                {
                    init_gen_[CalculateIndex(col, row)] = {col, row, 0, CellState::Dead};
                }
            }
        }
        init_population_ = population;
        population_ = population;
        curr_gen_ = init_gen_;
    }

    void Game::ComputeNextGeneration()
    {
        if (IsComplete())
        {
            game_state_ = GameState::Completed;
            return;
        }

        int population = 0;

        for (int col = 0; col < gol_config_.width_; col++)
        {
            for (int row = 0; row < gol_config_.height_; row++)
            {
                CellDetail cell_detail = GetCell(curr_gen_, col, row);
                CellDetail new_cell_detail = CellNextState(curr_gen_, cell_detail);

                if (new_cell_detail.state_ == CellState::Alive)
                {
                    population++;
                }

                SetCellStatus(next_gen_, new_cell_detail);
            }
        }

        population_ = population;
        generation_++;
        std::swap(curr_gen_, next_gen_);
    }

    void Game::ResizeGrid(int width, int height)
    {
        init_gen_.resize(width * height);
        curr_gen_.resize(width * height);
        next_gen_.resize(width * height);
    }

    void Game::SetCellStatus(std::vector<CellDetail> &gen_buf, const CellDetail &cell_detail)
    {
        int index = CalculateIndex(cell_detail.x_, cell_detail.y_);
        gen_buf[index] = cell_detail;
    }

    void Game::SetCellStatuses(std::vector<CellDetail> &gen_buf, const std::vector<CellDetail> &cell_details)
    {
        for (const auto &cell_detail : cell_details)
        {
            SetCellStatus(gen_buf, cell_detail);
        }
    }

    void Game::ResetGame()
    {
        curr_gen_ = init_gen_;
        SetAllDead(next_gen_);

        population_ = init_population_;
        generation_ = 0;
        game_state_ = GameState::Paused;
    }

    void Game::ClearGame()
    {
        SetAllDead(curr_gen_);
        SetAllDead(next_gen_);

        population_ = 0;
        generation_ = 0;
        game_state_ = GameState::Paused;
    }

    void Game::SetAllDead(std::vector<CellDetail> &cell_details)
    {
        for (auto &cell_detail : cell_details)
        {
            cell_detail.state_ = CellState::Dead;
        }
    }

    bool Game::OnGrid(int x, int y) const
    {
        return x >= 0 && x <= gol_config_.width_
            && y >= 0 && y <= gol_config_.height_;
    }

    int Game::CheckAliveNeighbors(std::vector<CellDetail> &gen_buf, int x, int y) const
    {
        // top, left, bottom, right, top-left, bottom-left, bottom-right, top-right
        std::vector<int> x_delta = {0, -1, 0, 1, -1, -1, 1,  1};
        std::vector<int> y_delta = {-1, 0, 1, 0, -1,  1, 1, -1};

        int count_neighbors{};

        for (int i = 0; i < 8; i++)
        {
            int col = x + x_delta[i];
            int row = y + y_delta[i];

            if (OnGrid(col, row) && GetCell(gen_buf, col, row).state_ == CellState::Alive)
            {
                count_neighbors++;
            }
        }
    }

    CellDetail Game::CellNextState(std::vector<CellDetail> &gen_buf, const CellDetail &cell_detail) const
    {

        CellDetail new_cell_detail = cell_detail;
        CellState cell_state = cell_detail.state_;
        int alive_neighbors = CheckAliveNeighbors(gen_buf, cell_detail.x_, cell_detail.y_);

        if (cell_state == CellState::Alive)
        {
            // cell death by under over population
            if (alive_neighbors < 2 || alive_neighbors >= 3)
            {
                new_cell_detail.age_ = 0;
                new_cell_detail.state_ = CellState::Dead;
            }
            // cell alive by having enough neighbors
            else if (alive_neighbors == 2 || alive_neighbors == 3)
            {
                new_cell_detail.age_++;
                new_cell_detail.state_ = CellState::Alive;
            }
        }
        else if (cell_state == CellState::Dead)
        {
            // cell alive by reproduction
            if (alive_neighbors == 3)
            {
                new_cell_detail.age_ = 0;
                new_cell_detail.state_ = CellState::Alive;
            }
        }

        return new_cell_detail;
    }
}