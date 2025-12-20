#include "game_manager/game_manager.hpp"
#include "game_logic/game.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_manager.hpp"
#include "render_manager/render_manager.hpp"

#include <iostream>
#include <thread>
#include <chrono>

namespace GOL
{
    void GameManager::RunGame()
    {
        game_.PauseGame();
        GOLStatus cmd_status = GOLStatus::Ok;
        std::string command{};

        while (!game_.IsQuit())
        {
            std::cout << "\033[2J\033[H";

            render_manager_.Render(gol_config_, game_);

            if (cmd_status != GOLStatus::Ok)
            {
                std::cout << "Invalid Command: " << command << "\n\n";
                command_manager_.DisplayAllCommandInfo();
            }

            std::cout << "Enter Command: ";

            if (std::getline(std::cin, command))
            {
                cmd_status = command_manager_.ExecuteCommand(command, gol_config_, game_);
            }

            while (game_.IsRunning())
            {
                std::cout << "\033[2J\033[H";
                render_manager_.Render(gol_config_, game_);
                game_.ComputeNextGeneration();
                std::this_thread::sleep_for(std::chrono::milliseconds(gol_config_.delay_ms_));
            }
        }
    }
}