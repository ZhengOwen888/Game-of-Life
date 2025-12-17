#ifndef GOL_STATUS_HPP
#define GOL_STATUS_HPP

namespace GOL
{
    /*************************************************************************
     * @enum A enum class of Status codes when setting the option of the game.
     ************************************************************************/
    enum class GOLStatus
    {
        Ok,
        GridTooSmall,
        InvalidOption,
        NotInitialized,
    };
}

#endif