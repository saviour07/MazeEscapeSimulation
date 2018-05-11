#ifndef _DIRECTION_H_
#define _DIRECTION_H_

#include <string>

namespace mes_direction
{
    enum Direction
    {
        North = 1,
        South,
        East,
        West,
        Out
    };

    std::wstring DirectionToString(Direction direction)
    {
        switch(direction)
        {
            case North:
                return L"North";
            case South:
                return L"South";
            case East:
                return L"East";
            case West:
                return L"West";
            case Out:
                return L"Out";
            default:
                return L"DEFAULT";
        }
    }
}

#endif