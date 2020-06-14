cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(nodes)
include_directories(include src)

add_executable(
    "${PROJECT_NAME}"
    src/node.cpp 
    main.cpp
)