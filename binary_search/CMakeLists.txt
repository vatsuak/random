cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(binary_search)
include_directories(include src)

# PROJECT_NAME -> binary_search
add_executable(
    "${PROJECT_NAME}"
    src/binary_search.cpp 
    src/eye_oh.cpp
)