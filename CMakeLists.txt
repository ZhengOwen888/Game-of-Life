cmake_minimum_required(VERSION 3.23)

# Set project name and language
project(Game_Of_Life LANGUAGES CXX)

# Set C++ Language Version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory("src/game_logic")
add_subdirectory("src/game_manager")
add_subdirectory("src/command_manager")
add_subdirectory("src/render_manager")

# Add executable
add_executable(main "src/main.cpp")

# Link dependencies and libraries
target_link_libraries(main
    PRIVATE
        game_logic_library
        game_manager_library
        command_manager_library
        render_manager_library
)