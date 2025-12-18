#ifndef GOL_GAME_LOGIC_HPP
#define GOL_GAME_LOGIC_HPP

#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "command_manager/config.hpp"

#include <iostream>
#include <vector>

namespace GOL
{
    /********************************************************
     * @class The main class for the Game of Life Simulation.
     *******************************************************/
    class Game
    {
        public:
            Game(GOLConfig &gol_config);

            /*********************************************************
             * @brief Run exactly one simulation.
             * @param steps The number of generation to run at a time.
             ********************************************************/
            void Step(int steps = 1);

            /*********************************************************
             * @brief Set a random initial state of the game.
             * @param alive_prob The probability that a cell is alive.
             ********************************************************/
            void RandomizeInit(double alive_prob = 0.0f);

            /****************************************
             * @brief Get the State of a single cell.
             * @param x The col position of the cell.
             * @param y The row position of the cell.
             ***************************************/
            CellState GetCell(int x, int y) const;

            /*************************************
             * @brief Compute the next generation.
             ************************************/
            void ComputeNextGeneration();

            /**************************************************
             * @brief Resize the grid that represents the game.
             * @param width The width of the grid.
             * @param height The height of the grid.
             *************************************************/
            void ResizeGrid(int width, int height);

            /**********************************************
             * @brief Set the State of a single cell.
             * @param cell_detail Details of a single cell.
             *********************************************/
            void SetCellStatus(CellDetail cell_detail);

            /***********************************************
             * @brief Set the State of many cells.
             * @param cell_details A vector of cell details.
             **********************************************/
            void SetCellStatuses(std::vector<CellDetail> cell_details);

            /*******************************************************************************
             * @brief Check if the simulation has reached the maximum number of generations.
             * @return True if reached max generation, false otherwise.
             ******************************************************************************/
            bool IsComplete() const;

            /*****************************************************************************
             * @brief Reset or Clear the Game of Life back to initial state with no cells.
             ****************************************************************************/
            void ResetGame();

        private:
            GOLConfig &gol_config_;

            std::vector<CellDetail> init_gen_{};
            std::vector<CellDetail> curr_gen_{};
            std::vector<CellDetail> next_gen_{};

            GameState game_state_{GameState::Stopped};

            int generation_count_{};
            bool initialized_{false};

    };
}

#endif