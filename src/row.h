#ifndef _ROW_H_
#define _ROW_H_

#include <vector>
#include <random>
#include <iostream>
#include "direction.h"

namespace mes_row
{
    using mes_direction::Direction;

    class Row
    {
    public:
        bool IsOutsideMaze(int position)
        {
            return mRow[position] == Direction::Out;
        }

        Direction GetDirection(int position)
        {
            return mRow[position];
        }

        void UpdateDirection(int previousPosition)
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

        void GenerateRows(int numberOfRows = 100)
        {
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(1,5);
            for (int i = 0; i < numberOfRows; ++i)
            {
                int randomNumber = distribution(generator);
                std::wcout << std::to_wstring(randomNumber) << std::endl;
                auto dir = static_cast<Direction>(randomNumber);
                std::wcout << DirectionToString(dir) << std::endl;
                mRow[i] = dir;
            }
        }

        void PrintRows()
        {
            for (size_t i = 0; i < mRow.size(); ++i)
            {
                std::wcout << DirectionToString(mRow[i]) << std::endl;
            }
        }

    private:
        std::vector<Direction> mRow;
    };
}

#endif