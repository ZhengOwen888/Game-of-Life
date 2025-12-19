#ifndef GOL_RENDER_MANAGER_HPP
#define GOL_RENDER_MANAGER_HPP

#include "render_manager/renderer.hpp"
#include "game_logic/game.hpp"
#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "command_manager/config.hpp"

namespace GOL
{
    class RenderManager
    {
        public:
            void Render(const Game &game, const GOLConfig &gol_config) const;

        private:
            Renderer renderer_;
    };
}

#endif