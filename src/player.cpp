#include "player.h"
#include "rng.h"
#include "direction.h"

#include <iostream>

namespace mes_player
{
    PlayerPosition Player::StartPosition(const mes_maze::Grid& rows)
    {
        // Account for the maze having a row of OUT directions at the top and bottom
        // Also account for the maze having a column of OUT directions at either side
        const int max = rows.size() - 2;
        {
            mes_rng::Rng rng;
            mCurrentXPosition = rng.GenerateNumber(1, max);
        }
        {
            mes_rng::Rng rng;
            mCurrentYPosition = rng.GenerateNumber(1, max);
        }

        PlayerPosition result;
        result.X = mCurrentXPosition;
        result.Y = mCurrentYPosition;
        return result;
    }

    bool Player::IsOutsideMaze(mes_maze::Grid& rows)
    {
        auto dirs = rows.at(mCurrentYPosition).GetDirections();
        const auto dir = dirs.at(mCurrentXPosition);
        std::wcout << L"Direction Name: " << dir.DirectionName() << std::endl;
        return dir.IsOut();
    }

    PlayerPosition Player::MoveDirection(mes_maze::Grid& rows)
    {
        const auto previousYPos = mCurrentYPosition;
        const auto previousXPos = mCurrentXPosition;

        auto dirs = rows.at(mCurrentYPosition).GetDirections();
        for (const auto& dir : dirs)
        {
            std::wcout << dir.DirectionName() << L" ";
        }
        std::wcout << std::endl;
        auto direction = dirs.at(mCurrentXPosition);
        if (direction.IsNorth())
        {
            std::wcout << L"Moving UP" << std::endl;
            mCurrentYPosition++;
        }
        if (direction.IsEast())
        {
            std::wcout << L"Moving RIGHT" << std::endl;
            mCurrentXPosition++;
        }
        if (direction.IsSouth())
        {
            std::wcout << L"Moving DOWN" << std::endl;
            mCurrentYPosition--;
        }
        if (direction.IsWest())
        {
            std::wcout << L"Moving LEFT" << std::endl;
            mCurrentXPosition--;
        }
        if (direction.IsOut())
        {
            std::wcout << L"Moving OUT" << std::endl;
            mCurrentXPosition = 0;
            mCurrentYPosition = 0;
        }
        rows.at(previousYPos).UpdateDirection(previousXPos);

        PlayerPosition result;
        result.X = mCurrentXPosition;
        result.Y = mCurrentYPosition;
        return result;
    }
}