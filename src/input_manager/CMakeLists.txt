cmake_minimum_required(VERSION 3.23)

# Collect Input Manager files
file(GLOB_RECURSE input_manager_src
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

#Create Input Manager Static Library
add_library(input_manager_library STATIC ${input_manager_src})

# Include directory for input_manager_library headers
target_include_directories(input_manager_library
    PUBLIC
        "${CMAKE_SOURCE_DIR}/include/input_manager"
)