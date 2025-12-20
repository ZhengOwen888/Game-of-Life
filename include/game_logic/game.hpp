#ifndef GOL_GAME_LOGIC_HPP
#define GOL_GAME_LOGIC_HPP

#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "command_manager/config.hpp"

#include <iostream>
#include <vector>
#include <random>

namespace GOL
{
    /********************************************************
     * @class The main class for the Game of Life Simulation.
     *******************************************************/
    class Game
    {
        public:
            Game(GOLConfig &gol_config)
                : gol_config_{gol_config}
            {
                ResizeGrid(gol_config_.width_,  gol_config_.height_);
            }

            /*********************************************************
             * @brief Set a random initial state of the game.
             ********************************************************/
            void RandomizeInit();

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


            /********************************************************************
             * @brief Set the State of a single cell.
             * @param gen_buf A reference to where we will store the cell detail.
             * @param cell_detail Details of a single cell.
             *******************************************************************/
            void SetCellStatus(std::vector<CellDetail> &gen_buf, const CellDetail &cell_detail);

            /*********************************************************************
             * @brief Set the State of many cells.
             * @param gen_buf A reference to where we will store the cell details.
             * @param cell_details A vector of cell details.
             ********************************************************************/
            void SetCellStatuses(std::vector<CellDetail> &gen_buf, const std::vector<CellDetail> &cell_details);

            /*********************************************************************
             * @brief Get the State of a single cell.
             * @param gen_buf A const reference to where we will store the cell details.
             * @param x The col position of the cell.
             * @param y The row position of the cell.
             ********************************************************************/
            const CellDetail &GetCell(const std::vector<CellDetail> &gen_buf, int x, int y) const
            { return gen_buf[CalculateIndex(x, y)]; }

            /*******************************************************************************
             * @brief Check if the simulation has reached the maximum number of generations.
             * @return True if reached max generation or population is 0, false otherwise.
             ******************************************************************************/
            bool IsComplete() const { return generation_ == gol_config_.generations_ || population_ == 0; }

            /****************************************************
             * @brief Return the simulation to its initial state.
             ***************************************************/
            void ResetGame();

            /************************************************************************
             * @brief Clear the current Grid and fill with new cells all set to Dead.
             ***********************************************************************/
            void ClearGame();

            /*************************************************
             * @brief Change the state of the game to running.
             ************************************************/
            void RunGame() { game_state_ = GameState::Running; };

            /*********************************************************************
             * @brief Check if the game is still running.
             * @return Returns true if the game is still running, false otherwise.
             ********************************************************************/
            bool IsRunning() const { return game_state_ == GameState::Running; };

            /************************
             * @brief Pause the game.
             ***********************/
            void PauseGame() { game_state_ = GameState::Paused; };

            /**************************************************************
             * @brief Check if the game is paused.
             * @return Returns true if the game is paused, false otherwise.
             *************************************************************/
            bool IsPaused() const { return game_state_ == GameState::Paused; };

            /***********************
             * @brief Quit the game.
             **********************/
            void QuitGame() {game_state_ = GameState::Quit; }

            /*************************************************************
             * @brief Check if the game has quit.
             * @return Returns true if the game has quit, false otherwise.
             ************************************************************/
            bool IsQuit() const {return game_state_ == GameState::Quit; }

            /********************************************************************************
             * @brief Get a const reference to the initial state of the game before starting.
             *******************************************************************************/
            const std::vector<CellDetail> &GetInitState() const { return init_gen_; };

            /**************************************************************************
             * @brief Get a reference to the initial state of the game before starting.
             *************************************************************************/
            std::vector<CellDetail> &GetMutableInitState() { return init_gen_; };

            /*******************************************************************************
             * @brief Get a const reference to the current state of the game after starting.
             ******************************************************************************/
            const std::vector<CellDetail> &GetCurrState() const {return curr_gen_; }

            /************************************************
             * @brief Get the current population of the game.
             ***********************************************/
            int Population() const { return population_; };

            /************************************************
             * @brief Get the current generation of the game.
             ***********************************************/
            int Generation() const {return generation_; };

        private:
            const GOLConfig &gol_config_; // game configuration read-only.
            GameState game_state_{GameState::Paused};

            int generation_{};
            int population_{};
            int init_population_{};

            std::vector<CellDetail> init_gen_{};
            std::vector<CellDetail> curr_gen_{};
            std::vector<CellDetail> next_gen_{};

            std::random_device rd_;
            std::mt19937 gen_{rd_()};

            /*************************************************************************
             * @brief Calculate the index of a 1D vector with the x (col) and y (row).
             ************************************************************************/
            int CalculateIndex(int x, int y) const { return y * gol_config_.width_ + x; };

            /**************************************************************
             * @brief Helper function to set all cells to dead.
             * @param cell_details A reference to a vector of cell details.
             *************************************************************/
            void SetAllDead(std::vector<CellDetail> &cell_details);

            /************************************************************************
             * @brief Helper function to check if a position is on the grid.
             * @param x Column.
             * @param y Row.
             * @return Returns true if the position is on the board, false otherwise.
             ***********************************************************************/
            bool OnGrid(int x, int y) const;

            /********************************************************************
             * @brief Check the number of alive neighbors around a single cell.
             * @param gen_buf A reference to where we will store the cell details.
             * @param x Column.
             * @param y Row.
             * @return Returns the number of alive neighbors aound a cell.
             *******************************************************************/
            int CheckAliveNeighbors(std::vector<CellDetail> &gen_buf, int x, int y) const;

            /********************************************************************
             * @brief Calculate a single cells next state.
             * @param gen_buf A reference to where we will store the cell details.
             * @param cell_detail The detail of a single cell.
             * @return The next state of the single cell.
             *******************************************************************/
            CellDetail CellNextState(std::vector<CellDetail> &gen_buf, const CellDetail &cell_detail) const;
    };
}

#endif