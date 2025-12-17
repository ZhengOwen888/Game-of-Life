#ifndef GOL_PREDEFINED_FLAG_HPP
#define GOL_PREDEFINED_FLAG_HPP

#include "command_manager/command_context.hpp"
#include "command_manager/status.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    /***********************************************************************
     * @brief function that validate and execute commands
     * @return std::pair<GOLStatus, size_t>, the status and tokens consumed.
     **********************************************************************/
    // Resize
    inline std::pair<GOLStatus, size_t> ResizeValidator(std::vector<std::string> tokens, size_t index);
    inline std::pair<GOLStatus, size_t> ResizeExecutor(CommandContext &cmd_context, size_t index);

    // Generation
    inline std::pair<GOLStatus, size_t> GenerationValidator(std::vector<std::string> tokens, size_t index);
    inline std::pair<GOLStatus, size_t> GenerationExecutor(CommandContext &cmd_context, size_t index);

    // Delay ms
    inline std::pair<GOLStatus, size_t> DelayMsValidator(std::vector<std::string> tokens, size_t index);
    inline std::pair<GOLStatus, size_t> DelayMsExecutor(CommandContext &cmd_context, size_t index);

    // Alive Probability
    inline std::pair<GOLStatus, size_t> AliveProbValidator(std::vector<std::string> tokens, size_t index);
    inline std::pair<GOLStatus, size_t> AliveProbExecutor(CommandContext &cmd_context, size_t index);

    // Cell Repr
    inline std::pair<GOLStatus, size_t> CellReprValidator(std::vector<std::string> tokens, size_t index);
    inline std::pair<GOLStatus, size_t> CellReprExecutor(CommandContext &cmd_context, size_t index);

    // Set Cells
    inline std::pair<GOLStatus, size_t> SetCellsValidator(std::vector<std::string> tokens, size_t index);
    inline std::pair<GOLStatus, size_t> SetCellsExecutor(CommandContext &cmd_context, size_t index);
}

#endif