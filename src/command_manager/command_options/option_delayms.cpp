#include "command_manager/command_options/set_command_options/option_delayms.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_option.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    std::pair<GOLStatus, size_t> CommandOptionDelayMs::Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const
    {
        if (index + arity_ > tokens.size())
        {
            return {GOLStatus::MissingArg, 0};
        }

        auto [delay_ms_status, delay_ms] = ConvertStrToInt(tokens[index + 1]);
        if (delay_ms_status != GOLStatus::Ok)
        {
            return {delay_ms_status, 0};
        }

        temp_gol_config.delay_ms_ = delay_ms;

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionDelayMs::Validate(GOLConfig &temp_gol_config) const
    {
        bool delay_ms_in_range = temp_gol_config.delay_ms_ >= GOLConstants::MIN_DELAY_MS && temp_gol_config.delay_ms_ <= GOLConstants::MAX_DELAY_MS;

        if (!delay_ms_in_range)
        {
            return {GOLStatus::ArgOutOfRange, 0};
        }

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionDelayMs::Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const
    {
        gol_config.delay_ms_ = temp_gol_config.delay_ms_;

        return {GOLStatus::Ok, arity_};
    }
}