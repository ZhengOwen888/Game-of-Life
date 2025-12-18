#include "command_manager/command.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/execution_context.hpp"

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <memory>

namespace GOL
{
    void Command::DisplayCommandInfo() const
    {
        std::cout << "Description: " << Description() << '\n';
        std::cout << "      Usage: " << Usage() << '\n';
        std::cout << "    Example: " << Example() << '\n';
        std::cout << "    Options: " << '\n';
        std::cout << FormatOptionDisplay() << '\n';
    }

    std::string Command::FormatOptionDisplay() const
    {
        std::string option_display{};

        for (const auto &option : options_)
        {
            option_display += std::string(6, ' ');
            option_display += '[';
            option_display += option->ShortFlag() + '|' + option->LongFlag();
            option_display += ']';
            option_display += ": " + option->Description() + '\n';
        }

        return option_display;
    }

    void Command::RegisterOption(const CommandOption &cmd_option)
    {
        options_.push_back(std::make_unique<CommandOption>(cmd_option));

        const CommandOption *cmd_option_stored = options_.back().get();

        flag_table_[cmd_option_stored->ShortFlag()] = cmd_option_stored;
        flag_table_[cmd_option_stored->LongFlag()] = cmd_option_stored;
    }
}