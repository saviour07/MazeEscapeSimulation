#include "row.h"
#include "rng.h"
namespace mes_row
{
    bool Row::IsOutsideMaze(int position)
    {
        return mRow[position].IsOut();
    }

    mes_direction::Direction Row::GetDirection(int position)
    {
        return mRow[position];
    }

    void Row::UpdateDirection(const int previousPosition)
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
    }

    void Row::GenerateRows(int numberOfRows)
    {
        for (int i = 0; i < numberOfRows; ++i)
        {
            mes_rng::Rng rng;
            const auto randomNumber = rng.GenerateNumber(1, 5);
            mes_direction::Direction dir(randomNumber);
            mRow.push_back(dir);
        }
    }
}