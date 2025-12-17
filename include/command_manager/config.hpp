#ifndef GOL_CONFIG_HPP
#define GOL_CONFIG_HPP

#include "game_logic/constants.hpp"

namespace GOL
{
    /************************************************************************
     * @struct A struct that details and set the config of the Game of Life.
     ***********************************************************************/
    struct GOLConfig
    {
        int width_{GOLConstants::DEFAULT_WIDTH};
        int height_{GOLConstants::DEFAULT_HEIGHT};
        int generations_{GOLConstants::DEFAULT_GENERATION};
        int delay_ms_{GOLConstants::DEFAULT_DELAY_MS};
        double alive_probability_{GOLConstants::DEFAULT_ALIVE_PROB};
        char cell_repr_{GOLConstants::DEFAULT_CHAR_REPR};
    };
}

#endif