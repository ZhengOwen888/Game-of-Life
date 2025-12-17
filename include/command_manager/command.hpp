#ifndef GOL_COMMAND_HPP
#define GOL_COMMAND_HPP

#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "command_manager/command_context.hpp"

#include <unordered_map>
#include <functional>
#include <vector>
#include <string>
#include <utility>

namespace GOL
{
    /** @brief A alias for a lamda function that validate a flag/option and its arguments. */
    using FlagValidator = std::function<std::pair<GOLStatus, size_t>(
        const std::vector<std::string> &tokens,
        size_t index
    )>;
    /** @brief A alias for a lamda function that execute a flag/option and its arguments. */
    using FlagExecutor = std::function<std::pair<GOLStatus, size_t>(
        CommandContext &cmd_context,
        size_t index
    )>;
    /***********************************************
     * @struct Contain deatails of a command option.
     **********************************************/
    struct CommandOption
    {
        std::string short_flag_{};
        std::string long_flag_{};
        std::string description_{};
    };

    /***************************************************************
     * @class An abstract class that represent a genericgol command.
     **************************************************************/
    class Command
    {
        public:
            /** @brief Construct a new GOLCommand object with a command name. */
            Command(const std::string &cmd_name)
                :cmd_name_{cmd_name}
            {}

            /** @brief Virtual destructor for safe polymorphic deletion. */
            virtual ~Command() = default;

            /*****************************************************************************
             * @brief Validate the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @return Return a GOLStatus to signal the success and failure of validation.
             ****************************************************************************/
            virtual GOLStatus Validate(const std::vector<std::string>& tokens) = 0;

            /****************************************************************************************
             * @brief Execute the command tokens.
             * @param cmd_context contains the details of a command to be executed.
             * @return Return a GOLStatus to signal the success and failture of Applying the command.
             ***************************************************************************************/
            virtual GOLStatus Execute(CommandContext &cmd_context) = 0;

            /*****************************************************************************
             * @brief Display the command name, description, usage, options, and exmaples.
             ****************************************************************************/
            void DisplayCommandInfo() const;

        protected:
            std::unordered_map<std::string, FlagValidator> flag_val_table_{};
            std::unordered_map<std::string, FlagExecutor> flag_exec_table_{};
            std::vector<CommandOption> options_{};

            /**************************************************************************************
             * @brief Get a const reference to a string that represent the name of the command.
             * @return Return a const reference to a string that represent the name of the command.
             *************************************************************************************/
            const std::string &Name() const { return cmd_name_; }

            /***************************************************************
             * @brief Provide a brief description of the command.
             * @return Return a string that describes what the command does.
             **************************************************************/
            virtual std::string Description() const = 0;

            /*****************************************************************************
             * @brief Provide the general template on how the command is used.
             * @return Return a string that shows how the general template of the command.
             ****************************************************************************/
            virtual std::string Usage() const { return "gol " + cmd_name_ + " [options] <args>"; }

            /****************************************************************************
             * @brief Provide an exmaple of how the command is used.
             * @return Returns a string that shows an example of how the command is used.
             ***************************************************************************/
            virtual std::string Example() const { return ""; }

            /**************************************************************
             * @brief Provide a vector osf options for a speicfied command.
             * @return Returns a vector of command option objects.
             *************************************************************/
            virtual std::vector<CommandOption> Options() const { return options_; }

            /***************************************************
             * @brief Registers a option for a specific command.
             **************************************************/
            void RegisterOption(const CommandOption &cmd_option, FlagValidator validator, FlagExecutor executor);

            /******************************************************
             * @brief Format the option into a displayable string.
             * @return Returns a string that represents the option.
             *****************************************************/
            std::string FormatOptionDisplay() const;

        private:
            std::string cmd_name_;
    };
}
#endif