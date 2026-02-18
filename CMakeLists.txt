cmake_minimum_required(VERSION 3.16)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/shuffle_board.cpp src/sudoku_grid.cpp src/sudoku_generator.cpp src/sudoku_solver.cpp)

include_directories(include)

add_executable(SudokuSolver ${SOURCE_FILES})

add_custom_target(run
    COMMAND ./SudokuSolver
    DEPENDS SudokuSolver
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})