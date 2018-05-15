#include "maze.h"

namespace mes_maze
{
    void Maze::GenerateMaze(const int rows, const int cols)
    {
        for (int idx = 0; idx < rows; ++idx)
        {
            mes_row::Row row;
            row.GenerateRow(idx, rows, cols);
            Rows.push_back(row);
        }
        //PrintRows();
    }

    void Maze::PrintRows() const
    {
        int x = 0;
        for (const auto& row : Rows)
        {
            std::wcout << L"Row " << ++x << std::endl;
            for (size_t y = 0; y < row.Count(); ++y)
            {
                std::wcout << "Col " << y << L": ";
                auto dirs = row.RowDirections();
                std::wcout << dirs.at(y).DirectionName() << std::endl; 
            }
        }
    }
}