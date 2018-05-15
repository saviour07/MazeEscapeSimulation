#ifndef _ROW_H_
#define _ROW_H_

#include <vector>
#include "direction.h"

namespace mes_row
{
    typedef std::vector<mes_direction::Direction> Directions;
    class Row
    {
    public:
        void UpdateDirection(const int xPos);
        void GenerateRow(const int rowIdx, const int numberOfRows, const int numberOfCols);

        size_t Count() const { return mRow.size(); }
        const Directions& GetDirections() const { return mRow; }

    private:
        Directions mRow;
    };
}

#endif