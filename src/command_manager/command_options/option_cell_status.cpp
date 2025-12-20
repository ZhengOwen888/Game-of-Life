#include "command_manager/command_options/set_command_options/option_cell_status.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_option.hpp"
#include "game_logic/cell_detail.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    std::pair<GOLStatus, size_t> CommandOptionCellStatus::Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const
    {
        if (index + arity_ > tokens.size())
        {
            return {GOLStatus::MissingArg, 0};
        }

        auto [col_status, col] = ConvertStrToInt(tokens[index + 1]);
        if (col_status != GOLStatus::Ok)
        {
            return {GOLStatus::InvalidArg, 0};
        }

        auto [row_status, row] = ConvertStrToInt(tokens[index + 2]);
        if (row_status != GOLStatus::Ok)
        {
            return {GOLStatus::InvalidArg, 0};
        }

        std::string cell_status = tokens[index + 3];

        if (cell_status == "alive")
        {
            temp_gol_config.alive_.push_back({col, row});
        }
        else if (cell_status == "dead")
        {
            temp_gol_config.dead_.push_back({col, row});
        }
        else
        {
            return {GOLStatus::InvalidArg, 0};
        }

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionCellStatus::Validate(GOLConfig &temp_gol_config) const
    {
        auto valid_position = [&](int col, int row) -> bool
        {
            return col >= 0 && col <= temp_gol_config.width_ - 1
                && row >= 0 && row <= temp_gol_config.height_ - 1;
        };

        for (const auto &[col, row] : temp_gol_config.alive_)
        {
            if (!valid_position(col, row))
            {
                return {GOLStatus::ArgOutOfRange, 0};
            }
        }

        for (const auto &[col, row] : temp_gol_config.dead_)
        {
            if (!valid_position(col, row))
            {
                return {GOLStatus::ArgOutOfRange, 0};
            }
        }

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionCellStatus::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        gol_config.alive_ = std::move(temp_gol_config.alive_);
        std::vector<CellDetail> cell_alive = CreateCellDetails(gol_config.alive_, CellState::Alive);
        game.SetCellStatuses(game.GetMutableInitState(), cell_alive);

        gol_config.dead_ = std::move(temp_gol_config.dead_);
        std::vector<CellDetail> cell_dead = CreateCellDetails(gol_config.dead_, CellState::Dead);
        game.SetCellStatuses(game.GetMutableInitState(), cell_dead);

        return {GOLStatus::Ok, arity_};
    }

    std::vector<CellDetail> CommandOptionCellStatus::CreateCellDetails(const std::vector<std::pair<int, int>> &positions, CellState cell_state) const
    {
        std::vector<CellDetail> cell_details{};
        int start_age = 0;

        for (const auto &[col, row] : positions)
        {
            cell_details.push_back({col, row, start_age, cell_state});
        }

        return cell_details;
    }
}