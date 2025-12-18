#include "command_manager/command_options/option_alive_prob.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/execution_context.hpp"
#include "command_manager/command_option.hpp"

#include <utility>
#include <vector>
#include <string>

namespace GOL
{
    std::pair<GOLStatus, size_t> CommandOptionAliveProb::Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const
    {
        if (index + arity_ >= tokens.size())
        {
            return {GOLStatus::MissingArg, 0};
        }

        auto [alive_probability_status, alive_probability] = ConvertStrToDouble(tokens[index + 1]);
        if (alive_probability_status != GOLStatus::Ok)
        {
            return {alive_probability_status, 0};
        }

        temp_gol_config.alive_probability_ = alive_probability;

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionAliveProb::Validate(GOLConfig &temp_gol_config) const
    {
        bool alive_probability_in_range = temp_gol_config.alive_probability_ >= GOLConstants::MIN_ALIVE_PROB && temp_gol_config.alive_probability_ <= GOLConstants::MAX_ALIVE_PROB;

        if (!alive_probability_in_range)
        {
            return {GOLStatus::ArgOutOfRange, 0};
        }

        return {GOLStatus::Ok, arity_};
    }

    std::pair<GOLStatus, size_t> CommandOptionAliveProb::Execute(ExecutionContext &exec_context, GOLConfig &temp_gol_config) const
    {
        exec_context.gol_config_.alive_probability_ = temp_gol_config.alive_probability_;

        return {GOLStatus::Ok, arity_};
    }
}