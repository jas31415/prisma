cmake_minimum_required(VERSION 3.10)
project(prisma)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(vendored)
add_subdirectory(src)