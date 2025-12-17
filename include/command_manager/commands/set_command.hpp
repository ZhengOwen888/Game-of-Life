#ifndef GOL_SET_COMMAND_HPP
#define GOL_SET_COMMAND_HPP

#include "command_manager/command.hpp"

namespace GOL
{
    class SetCommand : public Command
    {
        public:
            SetCommand()
                :Command("set")
            {}

            /*****************************************************************************
             * @brief Validate the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @return Return a GOLStatus to signal the success and failure of validation.
             ****************************************************************************/
            GOLStatus Validate(const std::vector<std::string>& tokens) override;

            /****************************************************************************************
             * @brief Execute the command tokens.
             * @param cmd_context contains the details of a command to be executed.
             * @return Return a GOLStatus to signal the success and failture of Applying the command.
             ***************************************************************************************/
            GOLStatus Execute(CommandContext &cmd_context) override;

        protected:
            std::string Description() const override
            {
                return "Set game options and settings.";
            }

            std::string Example() const override
            {
                return "gol set --width 3 --height 10 --generation 100";
            }
    };
}

#endif