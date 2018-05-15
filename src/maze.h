#ifndef _MAZE_H_H
#define _MAZE_H_H

#include <vector>
#include "row.h"

namespace mes_maze
{
    typedef std::vector<mes_row::Row> Grid;
    class Maze
    {
        public:
            void GenerateMaze(const int rows, const int cols);
            Grid Rows;
    };
}

#endif