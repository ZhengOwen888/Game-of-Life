#ifndef GOL_GAME_MANAGER_HPP
#define GOL_GAME_MANAGER_HPP

#include "game_logic/game.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_manager.hpp"
#include "render_manager/render_manager.hpp"

#include <iostream>

namespace GOL
{
    class GameManager
    {
        public:
            /********************************
             * @brief Run the main game loop.
             *******************************/
            void RunGame();

        private:
            GOLConfig gol_config_{};
            Game game_{gol_config_};
            CommandManager command_manager_{};
            RenderManager render_manager_{};
    };
}

#endif