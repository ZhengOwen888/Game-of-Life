#include "command_manager/commands/set_command.hpp"
#include "command_manager/command.hpp"
#include "command_manager/execution_context.hpp"
#include "command_manager/config.hpp"
#include "command_manager/status.hpp"

#include <vector>
#include <string>

namespace GOL
{
    void SetCommand::RegisterAllOptions()
    {

    }

    GOLStatus SetCommand::Parse(const std::vector<std::string> &tokens)
    {
    }

    GOLStatus SetCommand::Validate(const std::vector<std::string> &tokens)
    {
    }

    GOLStatus SetCommand::Execute(ExecutionContext &exec_context)
    {
    }

}