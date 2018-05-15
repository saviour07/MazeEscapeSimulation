#include "player.h"
#include "rng.h"
#include "direction.h"

#include <iostream>

namespace mes_player
{
    Player::Player(const int mazeSize)
    {
        {
            mes_rng::Rng rng;
            mCurrentXPosition = rng.GenerateNumber(1, mazeSize - 1);
        }
        {
            mes_rng::Rng rng;
            mCurrentYPosition = rng.GenerateNumber(1, mazeSize - 1);
        }
    }

    bool Player::IsOutsideMaze(mes_maze::Grid& rows)
    {
        auto row = rows.at(mCurrentYPosition);
        std::wcout << L"mCurrentYPosition: " << std::to_wstring(mCurrentYPosition) << std::endl;
        auto dirs = row.RowDirections();
        for (const auto& dir : dirs)
        {
            std::wcout << dir.DirectionName() << L" ";
        }
        std::wcout << std::endl;
        std::wcout << L"mCurrentXPosition: " << std::to_wstring(mCurrentXPosition) << std::endl;
        const auto dir = dirs[mCurrentXPosition];
        std::wcout << L"Direction Name: " << dir.DirectionName() << std::endl;
        return dir.IsOut();
    }

    void Player::MoveDirection(mes_maze::Grid& rows)
    {
        mPreviousXPosition = mCurrentXPosition;
        mPreviousYPosition = mCurrentYPosition;
        auto direction = rows.at(mPreviousYPosition).UpdateDirection(mPreviousXPosition);
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
    }
}