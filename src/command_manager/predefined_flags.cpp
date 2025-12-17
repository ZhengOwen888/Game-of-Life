#include "command_manager/predefined_flags.hpp"
#include "command_manager/status.hpp"
#include "game_logic/constants.hpp"

#include <utility>

namespace GOL
{
    auto ResizeValidator = [](std::vector<std::string> tokens, size_t index) -> std::pair<GOLStatus, size_t>
    {
        if (index + 2 >= tokens.size())
        {
            return std::make_pair(GOLStatus::MissingArg, 0);
        }

        std::string width_str{tokens[index + 1]};
        std::string height_str{tokens[index + 2]};
        int width{};
        int height{};

        try
        {
            width = std::stoi(width_str);
            height = std::stoi(height_str);
        }
        catch(const std::invalid_argument& e)
        {
            return std::make_pair(GOLStatus::InvalidArg,0);
        }
        catch (const std::out_of_range& e)
        {
            return std::make_pair(GOLStatus::ArgOutOfRange, 0);
        }

        return std::make_pair(GOLStatus::Ok, 3);
    };

    auto ResizeExecutor = [](CommandContext &cmd_context, size_t index) -> std::pair<GOLStatus, size_t>
    {
        std::string width_str{cmd_context.tokens_[index + 1]};
        std::string height_str{cmd_context.tokens_[index + 2]};
        int width = std::stoi(width_str);
        int height = std::stoi(height_str);

        cmd_context.gol_config_.width_ = width;
        cmd_context.gol_config_.height_ = height;
        cmd_context.game_.ResizeGrid(width, height);

        return std::make_pair(GOLStatus::Ok, 3);
    };

    // Generation
    auto GenerationValidator = [](std::vector<std::string> tokens, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto GenerationExecutor = [](CommandContext &cmd_context, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto DelayMsValidator = [](std::vector<std::string> tokens, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto DelayMsExecutor = [](CommandContext &cmd_context, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto AliveProbValidator = [](std::vector<std::string> tokens, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto AliveProbExecutor = [](CommandContext &cmd_context, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto CellReprValidator = [](std::vector<std::string> tokens, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto CellReprExecutor = [](CommandContext &cmd_context, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto SetCellsValidator = [](std::vector<std::string> tokens, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };

    auto SetCellsExecutor = [](CommandContext &cmd_context, size_t index) -> std::pair<GOLStatus, size_t>
    {
    };
}