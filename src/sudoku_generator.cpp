#include "sudoku_generator.hpp"

std::vector<FieldList> field_list(std::vector<std::vector<int>>& sudoku_table)
{
    std::vector<FieldList> fields;

    for(size_t row = 0; row < sudoku_table.size(); row++)
    {
        for(size_t col = 0; col < sudoku_table[row].size(); col++)
        {
            fields.push_back({row, col});
        }
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(fields.begin(), fields.end(), std::default_random_engine(seed));

    return fields;
}

std::vector<FieldList> sudoku_generator()
{
    
}