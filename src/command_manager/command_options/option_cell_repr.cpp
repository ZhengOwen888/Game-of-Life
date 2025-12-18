#include "command_manager/command_options/set_command_options/option_cell_repr.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_option.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    std::pair<GOLStatus, size_t> CommandOptionCellRepr::Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const
    {
        if (index + arity_ >= tokens.size())
        {
            return {GOLStatus::MissingArg, 0};
        }

        std::string temp_char_repr = tokens[index + 1];

        if (temp_char_repr.size() != 1)
        {
            return {GOLStatus::InvalidArg, 0};
        }

        temp_gol_config.cell_repr_ = temp_char_repr.at(0);

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionCellRepr::Validate(GOLConfig &temp_gol_config) const
    {
        bool cell_repr_in_range = temp_gol_config.cell_repr_ >= GOLConstants::MIN_VALID_CHAR_REPR && temp_gol_config.cell_repr_ <= GOLConstants::MAX_VALID_CHAR_REPR;

        if (!cell_repr_in_range)
        {
            return {GOLStatus::ArgOutOfRange, 0};
        }

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionCellRepr::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        gol_config.cell_repr_ = temp_gol_config.cell_repr_;

        return {GOLStatus::Ok, arity_};
    }
}