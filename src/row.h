#pragma once

#include <vector>
#include "direction.h"

namespace mes_row
{
    typedef std::vector<mes_direction::Direction> Directions;
    class Row
    {
    public:
        Row(const int rowNumber, const bool isLastRow = false)
            : mRowNumber(rowNumber), mIsLastRow(isLastRow)
        {
        }
        void UpdateDirection(const int xPos);
        void GenerateRow(const int numberOfCols);

        size_t Count() const { return mRow.size(); }
        const Directions& GetDirections() const { return mRow; }

    private:
        int mRowNumber = 0;
        bool mIsLastRow = false;
        Directions mRow;
    };
}
