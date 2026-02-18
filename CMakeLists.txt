cmake_minimum_required(VERSION 3.13)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp)

add_executable(SudokuSolver ${SOURCE_FILES})

add_custom_target(run
    COMMAND ./SudokuSolver
    DEPENDS SudokuSolver
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})