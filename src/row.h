#ifndef _ROW_H_
#define _ROW_H_

#include <vector>
#include "direction.h"

namespace mes_row
{
    class Row
    {
    public:
        bool IsOutsideMaze(int position);
        mes_direction::Direction GetDirection(int position);
        void UpdateDirection(const int previousPosition);
        void GenerateRows(int numberOfRows = 100);

    private:
        std::vector<mes_direction::Direction> mRow;
    };
}

#endif