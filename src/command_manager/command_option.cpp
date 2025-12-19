#include "command_manager/command_option.hpp"
#include "command_manager/status.hpp"
#include "command_manager/config.hpp"

#include <string>
#include <utility>

namespace  GOL
{
    std::pair<GOLStatus, int> CommandOption::ConvertStrToInt(const std::string &str) const
    {
        try
        {
            int num = std::stoi(str);
            return {GOLStatus::Ok, num};
        }
        catch (const std::invalid_argument &e)
        {
            return {GOLStatus::InvalidArg, 0};
        }
        catch (const std::out_of_range &e)
        {
            return {GOLStatus::ArgOutOfRange, 0};
        }

        return {GOLStatus::InvalidArg, 0};
    }

    std::pair<GOLStatus, double> CommandOption::ConvertStrToDouble(const std::string &str) const
    {
        try
        {
            double num = std::stod(str);
            return {GOLStatus::Ok, num};
        }
        catch (const std::invalid_argument &e)
        {
            return {GOLStatus::InvalidArg, 0.f};
        }
        catch (const std::out_of_range &e)
        {
            return {GOLStatus::ArgOutOfRange, 0.f};
        }

        return {GOLStatus::InvalidArg, 0.f};
    }
}