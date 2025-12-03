cmake_minimum_required(VERSION 4.0)
project(AdventOfCode_2025)

set(CMAKE_CXX_STANDARD 20)

# Include input data
configure_file(
        inputData/Day1_input.txt inputData/Day1_input.txt COPYONLY
)

add_executable(AdventOfCode_2025 main.cpp
        solutions/Day1.h
        solutions/Day1.cpp
)