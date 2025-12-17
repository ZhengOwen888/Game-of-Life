#ifndef GOL_COMMAND_HEADER
#define GOL_COMMAND_HEADER

#include "command_manager/status.hpp"
#include "command_manager/options.hpp"

#include "game_logic/gol.hpp"

#include <string>
#include <utility>

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
        virtual GOLStatus ValidateTokens(const std::vector<std::string>& tokens) = 0;

        /****************************************************************************************
         * @brief Execute the command tokens.
         * @param tokens A const reference to a vector of command tokens.
         * @param gol_options A reference to the current options of this game.
         * @param game A reference to the actual gol game state.
         * @return Return a GOLStatus to signal the success and failture of Applying the command.
         ***************************************************************************************/
        virtual GOLStatus ExecuteCommandTokens(const std::vector<std::string>& tokens, GOLOptions &gol_options, GOL &game) = 0;

        /**************************************************************************************
         * @brief Get a const reference to a string that represent the name of the command.
         * @return Return a const reference to a string that represent the name of the command.
         *************************************************************************************/
        const std::string &Name() const;

        /********************************************************
         * @brief Provide a brief description of the command.
         * @return A string that describes what the command does.
         *******************************************************/
        std::string Description() const;

        /**********************************************************************
         * @brief Provide the general template on how the command is used.
         * @return A string that shows how the general template of the command.
         *********************************************************************/
        std::string Usage() const;

        /********************************************************************
         * @brief Provide an exmaple of how the command is used.
         * @return A string that shows an example of how the command is used.
         *******************************************************************/
        std::string Example() const;

    private:
        std::string cmd_name_;
};

#endif