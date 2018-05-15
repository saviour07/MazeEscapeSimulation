#include "maze.h"

namespace mes_maze
{
    void Maze::GenerateMaze(const int rows, const int cols)
    {
        for (int rowIdx = 0; rowIdx < rows; ++rowIdx)
        {
            mes_row::Row row;
            row.GenerateRow(rowIdx, rows, cols);
            Rows.push_back(row);
        }
    }
}
