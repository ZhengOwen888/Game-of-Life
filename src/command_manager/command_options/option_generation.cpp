#include "command_manager/command_options/set_command_options/option_generation.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_option.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    std::pair<GOLStatus, size_t> CommandOptionGeneration::Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const
    {
        if (index + arity_ >= tokens.size())
        {
            return {GOLStatus::MissingArg, 0};
        }

        auto [generations_status, generations] = ConvertStrToInt(tokens[index + 1]);
        if (generations_status != GOLStatus::Ok)
        {
            return {generations_status, 0};
        }

        temp_gol_config.generations_ = generations;

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionGeneration::Validate(GOLConfig &temp_gol_config) const
    {
        bool generations_in_range = temp_gol_config.generations_ >= GOLConstants::MIN_GENERATION && temp_gol_config.generations_ <= GOLConstants::MAX_GENERATION;

        if (!generations_in_range)
        {
            return {GOLStatus::ArgOutOfRange, 0};
        }

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionGeneration::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        gol_config.generations_ = temp_gol_config.generations_;

        return {GOLStatus::Ok, arity_};
    }
}