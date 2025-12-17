#ifndef GOL_COMMAND_CONTEXT
#define GOL_COMMAND_CONTEXT

#include "game_logic/game.hpp"
#include "command_manager/config.hpp"

#include <string>
#include <vector>

namespace GOL
{
    /** @struct Contains the details of a command to be executed. */
    struct CommandContext
    {
        const std::vector<std::string> tokens_;
        GOLConfig &gol_config_;
        Game &game_;
    };
}

#endif