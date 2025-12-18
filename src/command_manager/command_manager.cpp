#include "command_manager/command_manager.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command.hpp"

#include "command_manager/commands/set_command.hpp"
#include "command_manager/commands/run_command.hpp"
#include "command_manager/commands/reset_command.hpp"

#include <sstream>
#include <string>
#include <memory>
#include <map>

namespace GOL
{
    const Command *CommandManager::GetCommand(const std::string &cmd_name) const
    {
        auto it = gol_cmd_table_.find(cmd_name);

        if (it != gol_cmd_table_.end())
        {
            return it->second;
        }

        return nullptr;
    }

    GOLStatus CommandManager::ExecuteCommand(const std::string &cmd_input, GOLConfig &gol_config, Game &game)
    {
        std::vector<std::string> tokens = Tokenize(cmd_input);

        if (tokens.size() < 2)
        {
            return GOLStatus::MissingArg;
        }

        std::string program_name = tokens[0];
        if (program_name != "gol")
        {
            return GOLStatus::InvalidProgram;
        }

        std::string command_name = tokens[1];
        auto it = gol_cmd_table_.find(command_name);
        if (it == gol_cmd_table_.end())
        {
            return GOLStatus::InvalidCommand;
        }

        const Command *command = it->second;
        GOLConfig temp_gol_config = gol_config;

        auto parse_status = command->Parse(tokens, temp_gol_config);
        if (parse_status != GOLStatus::Ok)
        {
            return parse_status;
        }

        auto validate_status = command->Validate(temp_gol_config);
        if (validate_status != GOLStatus::Ok)
        {
            return validate_status;
        }

        command->Execute(game, gol_config, temp_gol_config);

        return GOLStatus::Ok;
    }

    std::vector<std::string> CommandManager::Tokenize(const std::string &cmd_input)
    {
        std::vector<std::string> tokens{};
        std::stringstream ss{cmd_input};
        std::string word{};

        while (ss >> word)
        {
            tokens.push_back(word);
        }

        return tokens;
    }

    void CommandManager::RegisterCommand(const Command &cmd)
    {
        gol_cmds_.push_back(std::make_unique<Command>(cmd));

        const Command *gol_cmd = gol_cmds_.back().get();

        gol_cmd_table_[gol_cmd->Name()] = gol_cmd;
    }

    void CommandManager::RegisterAllCommands()
    {
        RegisterCommand(SetCommand{});
    }
}