#include "maze.h"
#include <iostream>

namespace mes_maze
{
    void Maze::GenerateMaze()
    {
        for (int rowIdx = 0; rowIdx < mRowCount; ++rowIdx)
        {
            mes_row::Row row(mLogger, rowIdx, rowIdx == mRowCount - 1);
            row.GenerateRow(mColCount);
            Rows.push_back(row);
        }

        PrintMaze();
    }

    void Maze::PrintMaze()
    {
        for (const auto& row : Rows)
        {
            for (const auto& dir : row.GetDirections())
            {
                const auto name = dir.DirectionName();
                mLogger.Write(name, false);

                auto len = name.size();
                while (len < 6)
                {
                    mLogger.Write(L" ", false);
                    len++;
                }
            }
            mLogger.Write(L"", true);
        }
    }
}
