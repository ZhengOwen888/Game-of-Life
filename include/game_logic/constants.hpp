#ifndef GOL_CONSTANTS_HPP
#define GOL_CONSTANTS_HPP

namespace GOL
{
    namespace GOLConstants
    {
        // == Valid Ranges == //
        inline constexpr int MIN_WIDTH = 1;
        inline constexpr int MAX_WIDTH = 100;

        inline constexpr int MIN_HEIGHT = 1;
        inline constexpr int MAX_HEIGHT = 100;

        inline constexpr int MIN_GENERATION = 1;
        inline constexpr int MAX_GENERATION = 1000;

        inline constexpr int MIN_DELAY_MS = 200;
        inline constexpr int MAX_DELAY_MS = 500;

        inline constexpr double MIN_ALIVE_PROB = 0.0;
        inline constexpr double MAX_ALIVE_PROB = 1.0;

        inline constexpr char MIN_VALID_CHAR_REPR = '!';
        inline constexpr char MAX_VALID_CHAR_REPR = '126';


        // == Default Values == //
        inline constexpr int DEFAULT_WIDTH = 10;
        inline constexpr int DEFAULT_HEIGHT = 10;
        inline constexpr int DEFAULT_GENERATION = 100;
        inline constexpr int DEFAULT_DELAY_MS = MIN_DELAY_MS;
        inline constexpr double DEFAULT_ALIVE_PROB = 0.3f;
        inline constexpr char DEFAULT_CHAR_REPR = '*';
    }
}

#endif