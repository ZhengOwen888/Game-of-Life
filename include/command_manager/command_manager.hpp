#ifndef GOL_COMMAND_MANAGER_HEADER
#define GOL_COMMAND_MANAGER_HEADER

#include "command_manager/status.hpp"
#include "command_manager/options.hpp"
#include "command_manager/command.hpp"

#include <string>
#include <memory>
#include <map>

class CommandManager
{
    public:
        /** @brief Construct a OptionMnager object */
        CommandManager(GOLOptions &gol_options);

        /***************************************************************************
         * @brief Get a pointer a command object by the specified name.
         * @param cmd_name The name of the command
         * @return  Return a pointer to the command if it exists, otherwise nullptr.
         **************************************************************************/
        Command* GetCommand(const std::string &cmd_name) const;

        /*******************************************************************************************
         * @brief Execute command input.
         * @param cmd_input A const reference to a string that represent the command to be executed.
         * @param game A reference to the actual gol game state.
         * @return Return a status code to signify the success or failure of executing the command.
         ******************************************************************************************/
        GOLStatus ExecuteCommandInput(const std::string &cmd_input, GOL &game);

    private:
        GOLOptions &gol_options_;
        std::map<std::string, std::unique_ptr<Command>> gol_cmds_;

        /*********************************************************************************************
         * @brief Tokenize command input.
         * @param cmd_input A const reference to a string that represent the command to be parsed.
         * @return Return a vector of tokens representin the commands.
         ********************************************************************************************/
        std::vector<std::string> Tokenize(const std::string &cmd_input);
};

#endif