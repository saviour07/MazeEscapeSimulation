#include "row.h"
#include "rng.h"

#include <iostream>

namespace mes_row
{
    mes_direction::Direction Row::UpdateDirection(const int previousPosition)
    {
        auto& direction = mRow[previousPosition];
        if (direction.IsNorth())
        {
            direction.ToEast();
        }
        if (direction.IsEast())
        {
            direction.ToSouth();
        }
        if (direction.IsSouth())
        {
            direction.ToWest();
        }
        if (direction.IsWest())
        {
            direction.ToNorth();
        }
        return direction;
    }

    void Row::GenerateRow(const int rowIdx, const int numberOfRows, const int numberOfCols)
    {
        for (int colIdx = 0; colIdx < numberOfCols; ++colIdx)
        {
            if (rowIdx == 0 || rowIdx == numberOfRows - 1
            || colIdx == 0 || colIdx == numberOfCols - 1)
            {
                auto dir = mes_direction::Direction(0);
                dir.ToOut();
                mRow.push_back(dir);
            }
            else
            {
                mes_rng::Rng rng;
                const auto randomNumber = rng.GenerateNumber(1, 4);
                mes_direction::Direction dir(randomNumber);
                mRow.push_back(dir);
            }
        }
    }
}