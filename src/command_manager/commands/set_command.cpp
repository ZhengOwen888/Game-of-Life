#include "command_manager/commands/set_command.hpp"
#include "command_manager/command.hpp"
#include "command_manager/.hpp"
#include "command_manager/config.hpp"
#include "command_manager/status.hpp"

#include "command_manager/command_options/set_command_options/option_resize.hpp"
#include "command_manager/command_options/set_command_options/option_generation.hpp"
#include "command_manager/command_options/set_command_options/option_delayms.hpp"
#include "command_manager/command_options/set_command_options/option_alive_prob.hpp"
#include "command_manager/command_options/set_command_options/option_cell_repr.hpp"
#include "command_manager/command_options/set_command_options/option_cell_status.hpp"

#include <vector>
#include <string>

namespace GOL
{
    void SetCommand::RegisterAllOptions()
    {
        RegisterOption(CommandOptionResize{});
        RegisterOption(CommandOptionGeneration{});
        RegisterOption(CommandOptionDelayMs{});
        RegisterOption(CommandOptionAliveProb{});
        RegisterOption(CommandOptionCellRepr{});
        RegisterOption(CommandOptionCellStatus{});
    }

    GOLStatus SetCommand::Parse(const std::vector<std::string> &tokens, GOLConfig &temp_gol_config) const
    {
        // The first two tokens are "gol" and "set" so we skip them
        size_t index = 2;

        while (index < tokens.size())
        {
            auto it = flag_table_.find(tokens[index]);

            if (it != flag_table_.end())
            {
                auto [flag, flag_handler] = *it;
                auto [parse_status, tokens_consumed] = flag_handler->Parse(tokens, index, temp_gol_config);

                if (parse_status != GOLStatus::Ok)
                {
                    return parse_status;
                }

                index += tokens_consumed;
            }
            else
            {
                return GOLStatus::InvalidOption;
            }
        }
        return GOLStatus::Ok;
    }

    GOLStatus SetCommand::Validate(GOLConfig &temp_configs) const
    {
        for (const auto &option : options_)
        {
            auto [validate_status, tokens_consumed] = option->Validate(temp_configs);

            if (validate_status != GOLStatus::Ok)
            {
                return validate_status;
            }
        }

        return GOLStatus::Ok;
    }

    GOLStatus SetCommand::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        for (const auto &option : options_)
        {
            auto [execute_status, tokens_consumed] = option->Execute(exec_context, temp_gol_config);

            if (execute_status != GOLStatus::Ok)
            {
                return execute_status;
            }
        }

        return GOLStatus::Ok;
    }
}