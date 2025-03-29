cmake_minimum_required(VERSION 3.26)
project(engine C CXX)

find_package(SDL3 REQUIRED)

add_executable(engine)

target_sources(engine
PRIVATE
    main.cpp
)

