#include "render_manager/renderer.hpp"
#include "game_logic/game.hpp"
#include "game_logic/cell_detail.hpp"
#include "game_logic/game_state.hpp"
#include "command_manager/config.hpp"

#include <vector>

namespace GOL
{
    void Renderer::Render(const Game &game, const GOLConfig &gol_config) const
    {
        std::vector<CellDetail> cell_details{};

        if (game.IsRunning())
        {
            cell_details = game.GetCurrState();
        }
        else
        {
            cell_details = game.GetInitState();
        }

        for (int col = 0; col < gol_config.width_; col++)
        {
            for (int row = 0; row < gol_config.height_; row++)
            {
                CellDetail cell_detail = game.GetCell(cell_details, col, row);
                if (cell_detail.state_ == CellState::Alive)
                {
                    std::cout << gol_config.cell_repr_;
                }
                else
                {
                    std::cout << '.';
                }
            }
            std::cout << '\n';
        }
        std::cout << "\nGeneration: " << game.Generation() << '|' << "Population: " << game.Population() << '\n';
    }
}