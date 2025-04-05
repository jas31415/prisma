cmake_minimum_required(VERSION 3.10)

# Add the vendored INTERFACE library
add_library(vendored INTERFACE)

# Set up raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(raylib EXCLUDE_FROM_ALL)
target_link_libraries(vendored INTERFACE raylib)