#include "direction.h"

namespace mes_direction
{
    Direction::Direction(const int randomNumber)
    {
        switch (randomNumber)
        {
            case 1:
            {
                mDirection = mNorthString;
                break;
            }
            case 2:
            {
                mDirection = mSouthString;
                break;
            }
            case 3:
            {
                mDirection = mEastString;
                break;
            }
            case 4:
            {
                mDirection = mWestString;
                break;
            }
            case 5:
            {
                mDirection = mOutString;
                break;
            }
            default:
                break;
        }
    }

    std::wstring Direction::DirectionName()
    {
        return mDirection;
    }

    bool Direction::IsNorth()
    {
        return mDirection.compare(mNorthString);
    }

    bool Direction::IsEast()
    {
        return mDirection.compare(mEastString);
    }

    bool Direction::IsSouth()
    {
        return mDirection.compare(mSouthString);
    }

    bool Direction::IsWest()
    {
        return mDirection.compare(mWestString);
    }

    bool Direction::IsOut()
    {
        return mDirection.compare(mOutString);
    }

    void Direction::ToNorth()
    {
        mDirection = mNorthString;
    }

    void Direction::ToEast()
    {
        mDirection = mEastString;
    }

    void Direction::ToSouth()
    {
        mDirection = mSouthString;
    }

    void Direction::ToWest()
    {
        mDirection = mWestString;
    }

    void Direction::ToOut()
    {
        mDirection = mOutString;
    }
}