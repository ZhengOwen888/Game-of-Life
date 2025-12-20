#include "command_manager/command.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"

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
}