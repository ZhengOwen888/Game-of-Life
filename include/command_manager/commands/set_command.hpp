#ifndef GOL_SET_COMMAND_HPP
#define GOL_SET_COMMAND_HPP

#include "command_manager/command.hpp"
#include "command_manager/execution_context.hpp"
#include "command_manager/config.hpp"
#include "command_manager/status.hpp"

#include <vector>
#include <string>

namespace GOL
{
    class SetCommand : public Command
    {
        public:
            SetCommand()
                :Command("set")
            {
                RegisterAllOptions();
            }

            /**************************************************************************
             * @brief Parse the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @return Return a GOLStatus to signal the success and failure of parsing.
             *************************************************************************/
            GOLStatus Parse(const std::vector<std::string> &tokens) override;

            /*****************************************************************************
             * @brief Validate the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @return Return a GOLStatus to signal the success and failure of validation.
             ****************************************************************************/
            GOLStatus Validate(const std::vector<std::string>& tokens) override;

            /****************************************************************************************
             * @brief Execute the command tokens.
             * @param exec_context contains the details of a command to be executed.
             * @return Return a GOLStatus to signal the success and failture of Applying the command.
             ***************************************************************************************/
            GOLStatus Execute(ExecutionContext &exec_context) override;

        private:
            GOLConfig temp_gol_config_{};

            /***************************************************************
             * @brief Provide a brief description of the command.
             * @return Return a string that describes what the command does.
             **************************************************************/
            std::string Description() const override
            {
                return "Set game options and settings.";
            }

            /****************************************************************************
             * @brief Provide an exmaple of how the command is used.
             * @return Returns a string that shows an example of how the command is used.
             ***************************************************************************/
            std::string Example() const override
            {
                return "gol set --width 3 --height 10 --generation 100";
            }

            /** @brief Register all options at once. */
            void RegisterAllOptions() override;

            std::pair<GOLStatus, size_t> ParseResize(std::vector<std::string> tokens, size_t index);
            std::pair<GOLStatus, size_t> ValidateResize(std::vector<std::string> tokens, size_t index);
            std::pair<GOLStatus, size_t> ExecuteResize(ExecutionContext &exec_context, size_t index);

            std::pair<GOLStatus, size_t> ParseGeneration(std::vector<std::string> tokens, size_t index);
            std::pair<GOLStatus, size_t> ValidateGeneration(std::vector<std::string> tokens, size_t index);
            std::pair<GOLStatus, size_t> ExecuteGeneration(ExecutionContext &exec_context, size_t index);

            std::pair<GOLStatus, size_t> ParseDelayMs(std::vector<std::string> tokens, size_t index);
            std::pair<GOLStatus, size_t> ValidateDelayMs(std::vector<std::string> tokens, size_t index);
            std::pair<GOLStatus, size_t> ExecuteDelayMs(ExecutionContext &exec_context, size_t index);

            std::pair<GOLStatus, size_t> ParseAliveProb(std::vector<std::string> tokens, size_t index);
            std::pair<GOLStatus, size_t> validateAliveProb(std::vector<std::string> tokens, size_t index);
    };
}

#endif