#include "player.h"

namespace mes_player
{
    using mes_direction::Direction;

    void Player::MoveDirection(Direction direction)
    {
        mPreviousPosition = mCurrentPosition;
        switch(direction)
        {
            // TODO: handle North, South, and Out
            case Direction::East:
            {
                mCurrentPosition++;
                break;
            }
            case Direction::West:
            {
                mCurrentPosition--;
                break;
            }
            default:
                break;
        }
    }

    int Player::GetCurrentPosition()
    {
        return mCurrentPosition;
    }
}