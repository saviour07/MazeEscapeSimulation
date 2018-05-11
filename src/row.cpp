#include "row.h"

namespace mes_row
{
    bool Row::IsOutsideMaze(int position)
    {
        return mRow[position] == Direction::Out;
    }

    Direction Row::GetDirection(int position)
    {
        return mRow[position];
    }

    void Row::UpdateDirection(int previousPosition)
    {
        const auto& direction = mRow[previousPosition];
        switch(direction)
        {
            case Direction::North:
            {
                mRow[previousPosition] = Direction::East;
                break;
            }
            case Direction::East:
            {
                mRow[previousPosition] = Direction::South;
                break;
            }
            case Direction::South:
            {
                mRow[previousPosition] = Direction::West;
                break;
            }
            case Direction::West:
            {
                mRow[previousPosition] = Direction::North;
                break;
            }
            default:
                break;
        }
    }

    void Row::GenerateRows(int numberOfRows = 100)
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1,5);
        for (int i = 0; i < numberOfRows; ++i)
        {
            int randomNumber = distribution(generator);
            std::wcout << std::to_wstring(randomNumber) << std::endl;
            auto dir = static_cast<Direction>(randomNumber);
            std::wcout << DirectionToString(dir) << std::endl;

            mRow[i] = dir;  // Segmentation fault on second iteration
        }
    }

    void Row::PrintRows()
    {
        for (auto i = 0; i < mRow.size(); ++i)
        {
            std::wcout << DirectionToString(mRow[i]) << std::endl;
        }
    }
}