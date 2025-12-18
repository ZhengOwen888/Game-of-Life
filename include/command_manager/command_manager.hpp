#ifndef GOL_COMMAND_MANAGER_HPP
#define GOL_COMMAND_MANAGER_HPP

#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command.hpp"
#include "game_logic/game.hpp"

#include <string>
#include <memory>
#include <map>

namespace GOL
{
    class CommandManager
    {
        public:
            /** @brief Construct a CommandManager object */
            CommandManager(GOLConfig &gol_config)
            {
                RegisterAllCommands();
            }

            /*******************************************************************************
             * @brief Get a pointer a command object by the specified name.
             * @param cmd_name The name of the command
             * @return  Return a pointer to a const command if it exists, otherwise nullptr.
             ******************************************************************************/
            const Command* GetCommand(const std::string &cmd_name) const;

            /*******************************************************************************************
             * @brief Execute command input.
             * @param cmd_input A const reference to a string that represent the command to be executed.
             * @param gol_config A reference to the actual game configuration.
             * @param game A reference to the actual gol game state.
             * @return Return a status code to signify the success or failure of executing the command.
             ******************************************************************************************/
            GOLStatus ExecuteCommand(const std::string &cmd_input, GOLConfig &gol_config_,  Game &game);

        private:
            std::map<std::string, const Command*> gol_cmd_table_;
            std::vector<std::unique_ptr<Command>> gol_cmds_;

            /*********************************************************************************************
             * @brief Tokenize command input.
             * @param cmd_input A const reference to a string that represent the command to be parsed.
             * @return Return a vector of tokens representin the commands.
             ********************************************************************************************/
            std::vector<std::string> Tokenize(const std::string &cmd_input);

            /***************************************************
             * @brief Register a single command.
             * @param cmd A const reference to a Command object.
             **************************************************/
            void RegisterCommand(const Command &cmd);

            /******************************************************************
             * @brief Register all the commands that CommandMnager will handle.
             *****************************************************************/
            void RegisterAllCommands();
    };
}

#endif