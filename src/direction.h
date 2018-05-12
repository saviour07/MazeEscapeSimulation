#ifndef _DIRECTION_H_
#define _DIRECTION_H_

#include <string>

namespace mes_direction
{
    class Direction
    {
        public:
            Direction(const int randomNumber);

            std::wstring DirectionName();
            
            bool IsNorth();
            bool IsEast();
            bool IsSouth();
            bool IsWest();
            bool IsOut();

            void ToNorth();
            void ToEast();
            void ToSouth();
            void ToWest();
            void ToOut();

        private:
            std::wstring mDirection;
            const std::wstring mNorthString = L"North";
            const std::wstring mSouthString = L"South";
            const std::wstring mEastString = L"East";
            const std::wstring mWestString = L"West";
            const std::wstring mOutString = L"Out";

            enum eDirections
            {
                North = 1,
                South,
                East,
                West,
                Out
            };
    };
}

#endif