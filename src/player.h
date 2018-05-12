#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "direction.h"

namespace mes_player
{
    class Player
    {
    public:
        void MoveDirection(mes_direction::Direction direction);
        int GetCurrentPosition();

    private:
        int mPreviousPosition = 0;
        int mCurrentPosition = 0;
    };
}

#endif