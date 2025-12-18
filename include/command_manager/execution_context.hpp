#ifndef GOL_execution_context
#define GOL_execution_context

#include "game_logic/game.hpp"
#include "command_manager/config.hpp"

#include <string>
#include <vector>

namespace GOL
{
    /****************************************************************
     * @brief Runtime environment in which commands are executed.
     *
     * Holds references to live application state. Does not own data.
     ***************************************************************/
    struct ExecutionContext
    {
        GOLConfig &gol_config_;
        Game &game_;
    };

}

#endif