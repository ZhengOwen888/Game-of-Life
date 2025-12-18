#ifndef GOL_COMMAND_OPTION_CELLSTATUS_HPP
#define GOL_COMMAND_OPTION_CELLSTATUS_HPP

#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/execution_context.hpp"
#include "command_manager/command_option.hpp"
#include "game_logic/cell_detail.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    class CommandOptionCellStatus : public CommandOption
    {
        public:
            CommandOptionCellStatus()
                : CommandOption{"-cs", "--cell-status", "set the status of the cell in the grid.", 4}
            {}

            /**********************************************************************************************
             * @brief Parse the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @param index The current index in the tokens vector from which parsing begins.
             * @param temp_gol_config A reference to a temporary GOLConfig object to store parsed values.
             * @return Return a GOLStatus to signal the success and failure of parsing and tokens consumed.
             *********************************************************************************************/
            std::pair<GOLStatus, size_t> Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const override;

            /*************************************************************************************************
             * @brief Validate the command tokens
             * @param temp_gol_config A reference to the temporary GOLConfig object containing parsed values.
             * @return Return a GOLStatus to signal the success and failure of validating and tokens consumed.
             ************************************************************************************************/
            std::pair<GOLStatus, size_t> Validate(GOLConfig &temp_gol_config) const override;

            /***************************************************************************************************
             * @brief Execute the command tokens
             * @param game A reference to the actual gol game state.
             * @param gol_config A reference to the actual game configuration.
             * @param temp_gol_config A reference to the temporary GOLConfig object containing validated values.
             * @return Return a GOLStatus to signal the success and failure of executing and tokens consumed.
             **************************************************************************************************/
            std::pair<GOLStatus, size_t> Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const override;

            /***************************************************************
             * @brief Create a more details vector of cell detail.
             * @param positions The positiosn that the cells will be placed.
             * @param cell_state The state of the cells.
             * @return A vector of Cell Details.
             **************************************************************/
            std::vector<CellDetail> CreateCellDetails(const std::vector<std::pair<int, int>> &positions, CellState cell_state) const;
    };
}

#endif