#ifndef GOL_OPTIONS_HEADER
#define GOL_OPTIONS_HEADER

/************************************************************************
 * @struct A struct that details and set the options of the Game of Life.
 ***********************************************************************/
struct GOLOptions
{
    int width_{10};
    int height_{10};
    int generations_{10};
    int delay_ms_{200};
    double alive_probability_{0.3f};
    char cell_repr_{'*'};
};

#endif