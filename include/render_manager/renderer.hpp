#ifndef GOL_RENDERER_HPP
#define GOL_RENDERER_HPP

#include "game_logic/game.hpp"
#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "command_manager/config.hpp"

#include <iostream>
#include <vector>

namespace GOL
{
    class Renderer
    {
        public:
            void Render(const GOLConfig &gol_config, const Game &game) const;
    };
}

#endif