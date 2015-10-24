set(PROJECT_NAME Schemepp)
cmake_minimum_required(VERSION 2.6)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLASH} -W)

file(GLOB_RECURSE TD_SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${TD_SOURCE_FILES})
include_directories(src/)
