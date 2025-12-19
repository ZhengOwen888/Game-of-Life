#include "render_manager/render_manager.hpp"
#include "render_manager/renderer.hpp"
#include "game_logic/game.hpp"
#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "command_manager/config.hpp"

namespace GOL
{
    void RenderManager::Render(const Game &game, const GOLConfig &gol_config) const
    {
        std::cout << "\033[H"; // move cursor to the top-left

        renderer_.Render(game, gol_config);
    }
}