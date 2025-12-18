#ifndef GOL_COMMAND_OPTION_HPP
#define GOL_COMMAND_OPTION_HPP

#include "command_manager/status.hpp"
#include "command_manager/config.hpp"
#include "game_logic/game.hpp"

#include <string>
#include <utility>

namespace GOL
{
    class CommandOption
    {
        public:
            /** @brief create a CommandOption object with short flag, long flag, a short description and tokens consumed. */
            CommandOption(const std::string &short_flag, const std::string &long_flag, const std::string &description, int arity)
                : short_flag_{short_flag}
                , long_flag_{long_flag}
                , description_{description}
                , arity_{arity}
            {}

            virtual ~CommandOption() = default;

            /**********************************************************************************************
             * @brief Parse the command tokens
             * @param tokens A const reference to a vector of command tokens.
             * @param index The current index in the tokens vector from which parsing begins.
             * @param temp_gol_config A reference to a temporary GOLConfig object to store parsed values.
             * @return Return a GOLStatus to signal the success and failure of parsing and tokens consumed.
             *********************************************************************************************/
            virtual std::pair<GOLStatus, size_t> Parse(const std::vector<std::string> &tokens, size_t index, GOLConfig &temp_gol_config) const = 0;

            /*************************************************************************************************
             * @brief Validate the command tokens
             * @param temp_gol_config A reference to the temporary GOLConfig object containing parsed values.
             * @return Return a GOLStatus to signal the success and failure of validating and tokens consumed.
             ************************************************************************************************/
            virtual std::pair<GOLStatus, size_t> Validate(GOLConfig &temp_gol_config) const = 0;

            /***************************************************************************************************
             * @brief Execute the command tokens
             * @param game A reference to the actual gol game state.
             * @param gol_config A reference to the actual game configuration.
             * @param temp_gol_config A reference to the temporary GOLConfig object containing validated values.
             * @return Return a GOLStatus to signal the success and failure of executing and tokens consumed.
             **************************************************************************************************/
            virtual std::pair<GOLStatus, size_t> Execute(Game &game, GOLConfig &gol_config, GOLConfig &temp_gol_config) const = 0;

            /** @brief Get the short flag representation of the option. */
            const std::string &ShortFlag() const { return short_flag_; }

            /** @brief Get the long flag representation of the option. */
            const std::string &LongFlag() const { return long_flag_; }

            /** @brief Get the short description of the option. */
            const std::string &Description() const { return description_; }

        protected:
            std::string short_flag_;
            std::string long_flag_;
            std::string description_;
            size_t arity_{};

            /** @brief Helper function to convert std::string to int. */
            std::pair<GOLStatus, int> ConvertStrToInt(const std::string &str) const;

            /** @brief Helper function to convert std::string to double. */
            std::pair<GOLStatus, double> ConvertStrToDouble(const std::string &str) const;
    };
}

#endif