#ifndef _ROW_H_
#define _ROW_H_

#include <vector>
#include "direction.h"

namespace mes_row
{
    class Row
    {
    public:
        mes_direction::Direction UpdateDirection(const int previousPosition);
        void GenerateRow(const int rowIdx, const int numberOfRows, const int numberOfCols);
        size_t Count() const { return mRow.size(); }
        const std::vector<mes_direction::Direction>& RowDirections() const { return mRow; }

    private:
        std::vector<mes_direction::Direction> mRow;
    };
}

#endif