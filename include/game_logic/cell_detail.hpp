#ifndef GOL_CELL_DETAIL_HPP
#define GOL_CELL_DETAIL_HPP

/******************************************************************************
 * @enum enum class that represents the state of the cell either Dead or Alive.
 *****************************************************************************/
enum class CellState
{
    Dead,
    Alive
};

/**********************************************************
 * @enum enum class that store the detail of a single cell.
 *********************************************************/
struct CellDetail
{
    int x_{}; // column
    int y_{}; // row
    int age_{};
    CellState state_{CellState::Dead};
};

#endif