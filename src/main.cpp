#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main()
{   
    srand( time( nullptr ) );

    //Solved sudoku board
    std::vector<std::vector<int>> sudoku_table = 
    {
        {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
        }
    };

    size_t random_1 = (std::rand() % 8) + 1;
    size_t random_2 = (std::rand() % 8) + 1;

    //std::cout << random_1 << " " << random_2 << std::endl << std::endl;

    if(random_1 == random_2)
    {
        if(random_1 == 1)
        {
            random_1 += 1;
        }
        else
        {
            random_1 -= 1;
        }
    }

    for(size_t i = 0; i < sudoku_table.size(); i++)
    {
        for(size_t j = 0; j < sudoku_table[i].size(); j++)
        {
            if(sudoku_table[i][j] == random_1)
            {
                sudoku_table[i][j] = random_2;
                continue;
            }

            if(sudoku_table[i][j] == random_2)
            {
                sudoku_table[i][j] = random_1;
                continue;
            }
        }
    }

    for(size_t block = 0; block < 3; block++)
    {
        size_t random_row_1 = block * 3 + std::rand() % 3;
        size_t random_row_2 = block * 3 + std::rand() % 3;

        sudoku_table[random_row_1].swap(sudoku_table[random_row_2]);
    }

    for(size_t block = 0; block < 3; block++)
    {
        size_t random_col_1 = block * 3 + std::rand() % 3;
        size_t random_col_2 = block * 3 + std::rand() % 3;

        for(size_t row = 0; row < sudoku_table.size(); row++)
        {
            std::swap(sudoku_table[row][random_col_1], sudoku_table[row][random_col_2]);
        }
    }

    size_t possibility = std::rand() % 2;

    if(possibility == 1)
    {
        std::vector<std::vector<int>> tmp_sudoku(sudoku_table[0].size(), std::vector<int>(sudoku_table.size()));

        for(size_t row = 0; row < sudoku_table.size(); row++)
        {
            for(size_t col = 0; col < sudoku_table[row].size(); col++)
            {
                tmp_sudoku[col][row] = sudoku_table[row][col];
            }
        }

        sudoku_table = tmp_sudoku;
    }

    //Tests
    //std::cout << random_1 << " " << random_2 << std::endl << std::endl;

    for(size_t i = 0; i < sudoku_table.size(); i++)
    {
        for(size_t j = 0; j < sudoku_table[i].size(); j++)
        {
            std::cout << sudoku_table[i][j];
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    return 0;
}