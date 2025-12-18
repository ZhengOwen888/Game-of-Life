#include "command_manager/command_options/set_command_options/option_resize.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/execution_context.hpp"
#include "command_manager/command_option.hpp"

#include "game_logic/constants.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    std::pair<GOLStatus, size_t> CommandOptionResize::Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const
    {
        if (index + arity_ >= tokens.size())
        {
            return {GOLStatus::MissingArg, 0};
        }

        auto [width_status, width] = ConvertStrToInt(tokens[index + 1]);
        if (width_status != GOLStatus::Ok)
        {
            return {width_status, 0};
        }

        auto [height_status, height] = ConvertStrToInt(tokens[index + 2]);
        if (height_status != GOLStatus::Ok)
        {
            return {height_status, 0};
        }

        temp_gol_config.width_ = width;
        temp_gol_config.height_ = height;

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionResize::Validate(GOLConfig &temp_gol_config) const
    {
        bool width_in_range = temp_gol_config.width_ >= GOLConstants::MIN_WIDTH && temp_gol_config.width_ <= GOLConstants::MAX_WIDTH;
        bool height_in_range = temp_gol_config.height_ >= GOLConstants::MIN_HEIGHT && temp_gol_config.height_ <= GOLConstants::MAX_HEIGHT;

        if (!width_in_range || !height_in_range)
        {
            return {GOLStatus::ArgOutOfRange, 0};
        }

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionResize::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        exec_context.gol_config_.width_ = temp_gol_config.width_;
        exec_context.gol_config_.height_ = temp_gol_config.height_;
        exec_context.game_.ResizeGrid(exec_context.gol_config_.width_, exec_context.gol_config_.height_);

        return {GOLStatus::Ok, arity_};
    }
}