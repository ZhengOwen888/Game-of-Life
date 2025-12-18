#include "command_manager.hpp"
#include "command_manager/status.hpp"

#include <string>

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
            option_display += option.short_flag_ + '|' + option.long_flag_;
            option_display += ']';
            option_display += ": " + option.description_ + '\n';
        }

        return option_display;
    }

    void Command::RegisterOption(const CommandOption &cmd_option, FlagParser parser, FlagValidator validator, FlagExecutor executor)
    {
        options_.push_back(cmd_option);

        flag_parse_table_[cmd_option.short_flag_] = parser;
        flag_parse_table_[cmd_option.long_flag_] = flag_parse_table_[cmd_option.short_flag_];

        flag_val_table_[cmd_option.short_flag_] = validator;
        flag_val_table_[cmd_option.long_flag_] = flag_val_table_[cmd_option.short_flag_];

        flag_exec_table_[cmd_option.short_flag_] = executor;
        flag_exec_table_[cmd_option.long_flag_] = flag_exec_table_[cmd_option.short_flag_];
    }
}