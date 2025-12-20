#ifndef GOL_QUIT_COMMAND_HPP
#define GOL_QUIT_COMMAND_HPP

#include "command_manager/command.hpp"
#include "command_manager/config.hpp"
#include "command_manager/status.hpp"

#include <vector>
#include <string>

namespace GOL
{
    class QuitCommand : public Command
    {
        public:
            QuitCommand()
                :Command("quit")
            {
                RegisterAllOptions();
            }

            /**************************************************************************
             * @brief Parse the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @param temp_gol_config A reference to a temp configuration of the game.
             * @return Return a GOLStatus to signal the success and failure of parsing.
             *************************************************************************/
            GOLStatus Parse(const std::vector<std::string> &tokens, GOLConfig &temp_gol_config) const override;

            /*****************************************************************************
             * @brief Validate the command tokens
             * @param temp_gol_config A reference to a temp configuration of the game.
             * @return Return a GOLStatus to signal the success and failure of validation.
             ****************************************************************************/
            GOLStatus Validate(GOLConfig &temp_configs) const override;

            /****************************************************************************************
             * @brief Execute the command tokens.
             * @param exec_context contains the details of a command to be executed.
             * @param temp_gol_config A reference to a temp configuration of the game.
             * @return Return a GOLStatus to signal the success and failture of Applying the command.
             ***************************************************************************************/
            GOLStatus Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const override;

        private:
            /***************************************************************
             * @brief Provide a brief description of the command.
             * @return Return a string that describes what the command does.
             **************************************************************/
            std::string Description() const override
            {
                return "Quit the game.";
            }

            /****************************************************************************
             * @brief Provide an exmaple of how the command is used.
             * @return Returns a string that shows an example of how the command is used.
             ***************************************************************************/
            std::string Example() const override
            {
                return "gol quit";
            }

            /**************************************
             * @brief Register all options at once.
             *
             * quit has no options.
             *************************************/
            void RegisterAllOptions() override {};
    };
}

#endif