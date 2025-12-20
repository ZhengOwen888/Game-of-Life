cmake_minimum_required(VERSION 3.23)

# Collect Render Manager files
file(GLOB_RECURSE render_manager_src
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

#Create Render Manager Static Library
add_library(render_manager_library STATIC ${render_manager_src})

# Include directory for render_manager_library headers
target_include_directories(render_manager_library
    PUBLIC
        "${CMAKE_SOURCE_DIR}/include"
)