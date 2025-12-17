cmake_minimum_required(VERSION 3.23)

# Collect Game Logic files
file(GLOB_RECURSE game_logic_src
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Create Game Logic Static Library
add_library(game_logic_library STATIC ${game_logic_src})

# Include directory for game_logic_library headers
target_include_directories(game_logic_library
    PUBLIC
        "${CMAKE_SOURCE_DIR}/include/game_logic"
)
