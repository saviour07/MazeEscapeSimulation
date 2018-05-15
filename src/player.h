#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "maze.h"

namespace mes_player
{
    class Player
    {
    public:
        Player(int mazeSize);
        bool IsOutsideMaze(mes_maze::Grid& mazeGrid);
        void MoveDirection(mes_maze::Grid& mazeGrid);
        const int& XPos() { return mCurrentXPosition; }
        const int& YPos() { return mCurrentYPosition; }

    private:
        int mPreviousXPosition = 1;
        int mCurrentXPosition = 1;
        int mPreviousYPosition = 1;
        int mCurrentYPosition = 1;
    };
}

#endif