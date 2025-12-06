cmake_minimum_required(VERSION 4.0.0...4.1.2)

project(polyfish VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE tests tests/*.cpp tests/*.hpp)

add_executable(polyfish ${sources})
target_include_directories(polyfish PRIVATE include)