#pragma once

#include "maze.h"

namespace mes_player
{
    struct PlayerPosition
    {
        int X;
        int Y;
    };

    class Player
    {
    public:
        PlayerPosition StartPosition(const int rowSize, const int colSize);
        bool IsOutsideMaze(mes_maze::Grid& mazeGrid);
        PlayerPosition MoveDirection(mes_maze::Grid& mazeGrid);

    private:
        int mCurrentXPosition = 1;
        int mCurrentYPosition = 1;

        void PrintDirections(const mes_row::Directions& directions);
    };
}
