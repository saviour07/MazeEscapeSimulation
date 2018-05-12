#include "player.h"

namespace mes_player
{
    void Player::MoveDirection(mes_direction::Direction direction)
    {
        mPreviousPosition = mCurrentPosition;
        if (direction.IsEast())
        {
            mCurrentPosition++;
        }
        if (direction.IsWest())
        {
            mCurrentPosition--;
        }
    }

    int Player::GetCurrentPosition()
    {
        return mCurrentPosition;
    }
}