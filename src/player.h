#ifndef _PLAYER_H_
#define _PLAYER_H_

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
        PlayerPosition StartPosition(const mes_maze::Grid& mazeGrid);
        bool IsOutsideMaze(mes_maze::Grid& mazeGrid);
        PlayerPosition MoveDirection(mes_maze::Grid& mazeGrid);

    private:
        int mCurrentXPosition = 1;
        int mCurrentYPosition = 1;
    };
}

#endif