#ifndef GOL_GAME_STATE_HPP
#define GOL_GAME_STATE_HPP

namespace GOL
{
    enum class GameState
    {
        Paused,     // Game is paused.
        Running,    // Game is currently still running.
        Completed,  // All generation completed or population is 0.
        Quit,       // Quit the game.
    };
}

#endif