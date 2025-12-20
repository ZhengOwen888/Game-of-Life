#include "render_manager/renderer.hpp"
#include "game_logic/game.hpp"
#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "command_manager/config.hpp"

#include <iostream>
#include <vector>

namespace GOL
{
    void Renderer::Render(const GOLConfig &gol_config, const Game &game) const
    {
        std::vector<CellDetail> cell_details{};

        if (game.IsRunning())
        {
            cell_details = game.GetCurrState();
        }
        else
        {
            cell_details = game.GetInitState();
        }

        std::cout << '\n';
        std::cout << '+' << std::string(gol_config.width_ * 2 + 5, '-') << "+\n";
        std::cout << '|' << std::string(gol_config.width_ * 2 + 5, ' ') << "|\n";

        for (int row = 0; row < gol_config.height_; row++)
        {
            std::cout << "|  [";
            for (int col = 0; col < gol_config.width_; col++)
            {
                CellDetail cell_detail = game.GetCell(cell_details, col, row);
                if (cell_detail.state_ == CellState::Alive)
                {
                    std::string cell_repr{};
                    cell_repr += "\033[32m";
                    cell_repr +=  gol_config.cell_repr_;
                    cell_repr += "\033[0m";

                    std::cout << cell_repr;
                }
                else
                {
                    std::cout << '.';
                }

                if (col < gol_config.width_ - 1)
                {
                    std::cout << ' ';
                }
            }
            std::cout << "]  |\n";
        }
        std::cout << '|' << std::string(gol_config.width_ * 2 + 5, ' ') << "|\n";
        std::cout << '+' << std::string(gol_config.width_ * 2 + 5, '-') << "+\n";
        std::cout << "\nGeneration: " << game.Generation() << " | " << "Population: " << game.Population() << "\n\n";
    }
}