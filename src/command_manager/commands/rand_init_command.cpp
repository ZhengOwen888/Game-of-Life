#include "command_manager/commands/rand_init_command.hpp"
#include "command_manager/command.hpp"
#include "command_manager/config.hpp"
#include "command_manager/status.hpp"

#include <vector>
#include <string>

namespace GOL
{
    GOLStatus RandInitCommand::Parse(const std::vector<std::string> &tokens, GOLConfig &temp_gol_config) const
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

        if (command_name != cmd_name_)
        {
            return GOLStatus::InvalidCommand;
        }

        return GOLStatus::Ok;
    }

    GOLStatus RandInitCommand::Validate(GOLConfig &temp_configs) const
    {
        return GOLStatus::Ok;
    }

    GOLStatus RandInitCommand::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        game.RandomizeInit();
        return GOLStatus::Ok;
    }
}
