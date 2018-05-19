#pragma once

#include <vector>
#include "row.h"

namespace mes_maze
{
    typedef std::vector<mes_row::Row> Grid;
    class Maze
    {
        public:
            Maze(const int rowCount, const int colCount)
                : mRowCount(rowCount + 2), mColCount(colCount + 2)
            {
            }
            void GenerateMaze();
            Grid Rows;

            const int& RowCount() { return mRowCount; }
            const int& ColCount() { return mColCount; }

        private:
            int mRowCount;
            int mColCount;

            void PrintMaze();
    };
}
