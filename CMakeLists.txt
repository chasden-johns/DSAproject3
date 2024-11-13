cmake_minimum_required(VERSION 3.27)
project(DSAproject3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSAproject3
        main.cpp
        medTree.cpp
        medTree.hpp)
