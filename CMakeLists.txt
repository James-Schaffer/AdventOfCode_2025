cmake_minimum_required(VERSION 4.0)
project(AdventOfCode_2025)

set(CMAKE_CXX_STANDARD 20)

# Include input data
configure_file(
        inputData/Day1_example_input.txt inputData/Day1_example_input.txt COPYONLY
        inputData/Day1_input.txt inputData/Day1_input.txt COPYONLY
)

add_executable(AdventOfCode_2025 main.cpp
        solutions/Day1_1.cpp
        solutions/Day1_1.h
        solutions/Day1_2.cpp
        solutions/Day1_2.h
)