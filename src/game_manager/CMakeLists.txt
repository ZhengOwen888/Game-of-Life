cmake_minimum_required(VERSION 3.23)

# Collect Game Manager files
file(GLOB_RECURSE game_manager_src
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

#Create Game Manager Static Library
add_library(game_manager_library STATIC ${game_manager_src})

# Include directory for game_manager_library headers
target_include_directories(game_manager_library
    PUBLIC
        "${CMAKE_SOURCE_DIR}/include"
)