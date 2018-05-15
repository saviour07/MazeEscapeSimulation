#include "row.h"
#include "rng.h"

#include <iostream>

namespace mes_row
{
    void Row::UpdateDirection(const int xPos)
    {
        auto& direction = mRow[xPos];
        if (direction.IsNorth())
        {
            std::wcout << "Moving NORTH to EAST" << std::endl;
            direction.ToEast();
        }
        else if (direction.IsEast())
        {
            std::wcout << "Moving EAST to SOUTH" << std::endl;
            direction.ToSouth();
        }
        else if (direction.IsSouth())
        {
            std::wcout << "Moving SOUTH to WEST" << std::endl;
            direction.ToWest();
        }
        else if (direction.IsWest())
        {
            std::wcout << "Moving WEST to NORTH" << std::endl;
            direction.ToNorth();
        }
        else if (direction.IsOut())
        {
            std::wcout << "OUT - Nothing to do!" << std::endl;
        }
    }

    void Row::GenerateRow(const int rowIdx, const int numberOfRows, const int numberOfCols)
    {
        for (int colIdx = 0; colIdx < numberOfCols; ++colIdx)
        {
            mes_direction::Direction dir;
            if (rowIdx == 0 || rowIdx == numberOfRows - 1   // Is first or last row
            || colIdx == 0 || colIdx == numberOfCols - 1)   // Is first or last direction
            {
                dir.ToOut();
            }
            else
            {
                mes_rng::Rng rng;
                const auto randomNumber = rng.GenerateNumber(1, 4);
                dir.StartDirection(randomNumber);
            }
            mRow.push_back(dir);
        }
    }
}