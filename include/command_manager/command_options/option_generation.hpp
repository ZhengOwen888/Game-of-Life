#ifndef GOL_COMMAND_OPTION_GENERATION_HPP
#define GOL_COMMAND_OPTION_GENERATION_HPP

#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/execution_context.hpp"
#include "command_manager/command_option.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    class CommandOptionGeneration : public CommandOption
    {
        public:
            CommandOptionGeneration()
                : CommandOption{"-g", "--generation", "set max generations.", 2}
            {}

            /**********************************************************************************************
             * @brief Parse the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @param index The current index in the tokens vector from which parsing begins.
             * @param temp_gol_config A reference to a temporary GOLConfig object to store parsed values.
             * @return Return a GOLStatus to signal the success and failure of parsing and tokens consumed.
             *********************************************************************************************/
            std::pair<GOLStatus, size_t> Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const;

            /*************************************************************************************************
             * @brief Validate the command tokens
             * @param temp_gol_config A reference to the temporary GOLConfig object containing parsed values.
             * @return Return a GOLStatus to signal the success and failure of validating and tokens consumed.
             ************************************************************************************************/
            std::pair<GOLStatus, size_t> Validate(GOLConfig &temp_gol_config) const;

            /***************************************************************************************************
             * @brief Execute the command tokens
             * @param exec_context Reference to the ExecutionContext where changes will be applied.
             * @param temp_gol_config A reference to the temporary GOLConfig object containing validated values.
             * @return Return a GOLStatus to signal the success and failure of executing and tokens consumed.
             **************************************************************************************************/
            std::pair<GOLStatus, size_t> Execute(ExecutionContext &exec_context, GOLConfig &temp_gol_config) const;
    };
}

#endif