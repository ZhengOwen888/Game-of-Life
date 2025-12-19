
#include "command_manager/commands/run_command.hpp"
#include "command_manager/command.hpp"
#include "command_manager/config.hpp"
#include "command_manager/status.hpp"

#include <vector>
#include <string>

namespace GOL
{
    GOLStatus RunCommand::Parse(const std::vector<std::string> &tokens, GOLConfig &temp_gol_config) const
    {
        if (tokens.size() != 2)
        {
            return GOLStatus::InvalidCommand;
        }

        std::string program_name = tokens[0];
        std::string command_name = tokens[1];

        if (program_name != "gol")
        {
            return GOLStatus::InvalidProgram;
        }
        if (command_name != "run")
        {
            return GOLStatus::InvalidCommand;
        }

        return GOLStatus::Ok;
    }

    GOLStatus RunCommand::Validate(GOLConfig &temp_configs) const
    {
        return GOLStatus::Ok;
    }

    GOLStatus RunCommand::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        game.RunGame();
        return GOLStatus::Ok;
    }
}