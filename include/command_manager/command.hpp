#ifndef GOL_COMMAND_HPP
#define GOL_COMMAND_HPP

#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_option.hpp"
#include "game_logic/game.hpp"

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <memory>

namespace GOL
{
    /***************************************************************
     * @class An abstract class that represent a genericgol command.
     **************************************************************/
    class Command
    {
        public:
            /** @brief Construct a new GOLCommand object with a command name. */
            Command(const std::string &cmd_name)
                :cmd_name_{cmd_name}
            {}

            /** @brief Virtual destructor for safe polymorphic deletion. */
            virtual ~Command() = default;

            /**************************************************************************
             * @brief Parse the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @param temp_gol_config A reference to a temp configuration of the game.
             * @return Return a GOLStatus to signal the success and failure of parsing.
             *************************************************************************/
            virtual GOLStatus Parse(const std::vector<std::string> &tokens, GOLConfig &temp_gol_config) const = 0;

            /*****************************************************************************
             * @brief Validate the command tokens
             * @param temp_gol_config A reference to a temp configuration of the game.
             * @return Return a GOLStatus to signal the success and failure of validation.
             ****************************************************************************/
            virtual GOLStatus Validate(GOLConfig &temp_configs) const = 0;

            /****************************************************************************************
             * @brief Execute the command tokens.
             * @param game A reference to the actual gol game state.
             * @param gol_config A reference to the actual game configuration.
             * @param temp_gol_config A reference to a temp configuration of the game.
             * @return Return a GOLStatus to signal the success and failture of Applying the command.
             ***************************************************************************************/
            virtual GOLStatus Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const = 0;

            /**************************************************************************************
             * @brief Get a const reference to a string that represent the name of the command.
             * @return Return a const reference to a string that represent the name of the command.
             *************************************************************************************/
            const std::string &Name() const { return cmd_name_; }

            /*****************************************************************************
             * @brief Display the command name, description, usage, options, and exmaples.
             ****************************************************************************/
            void DisplayCommandInfo() const;

        protected:
            std::string cmd_name_;
            std::unordered_map<std::string, const CommandOption*> flag_table_{};
            std::vector<std::unique_ptr<CommandOption>> options_{};

            /***************************************************************
             * @brief Provide a brief description of the command.
             * @return Return a string that describes what the command does.
             **************************************************************/
            virtual std::string Description() const = 0;

            /*****************************************************************************
             * @brief Provide the general template on how the command is used.
             * @return Return a string that shows how the general template of the command.
             ****************************************************************************/
            virtual std::string Usage() const { return "gol " + cmd_name_ + " [options] <args>"; }

            /****************************************************************************
             * @brief Provide an exmaple of how the command is used.
             * @return Returns a string that shows an example of how the command is used.
             ***************************************************************************/
            virtual std::string Example() const = 0;

            /************************************************************************
             * @brief Provide a vector of options for a speicfied command.
             * @return Returns const reference to a vector of command option objects.
             ***********************************************************************/
            const std::vector<std::unique_ptr<CommandOption>> &Options() const { return options_; }

            /** @brief Register all options at once. */
            virtual void RegisterAllOptions() = 0;

            /******************************************************
             * @brief Format the option into a displayable string.
             * @return Returns a string that represents the option.
             *****************************************************/
            std::string FormatOptionDisplay() const;
    };
}
#endif