cmake_minimum_required(VERSION 3.23)

# Collect Command Manager files
file(GLOB_RECURSE command_manager_src
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

#Create Command Manager Static Library
add_library(command_manager_library STATIC ${command_manager_src})

# Include directory for option_manager_library headers
target_include_directories(command_manager_library
    PUBLIC
        "${CMAKE_SOURCE_DIR}/include"
)