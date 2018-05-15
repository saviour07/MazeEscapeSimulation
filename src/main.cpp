#include <string>
#include <iostream>
#include "player.h"
#include "maze.h"

bool Simulate(mes_maze::Maze& maze, mes_player::Player player);

int main()
{
    mes_maze::Maze maze;
    maze.GenerateMaze(12, 12);

    mes_player::Player player(12);
    std::wcout << L"Start X: " << player.XPos() << std::endl;
    std::wcout << L"Start Y: " << player.YPos() << std::endl;

    if (Simulate(maze, player))
    {
        std::wcout << L"Out" << std::endl;
    }

    std::cin.get();
    return 0;
}

bool Simulate(mes_maze::Maze& maze, mes_player::Player player)
{
    int turn = 0;
    while (!player.IsOutsideMaze(maze.Rows))
    {
        std::wcout << L"Turn: " << std::to_wstring(++turn) << std::endl;
        player.MoveDirection(maze.Rows);

        std::wcout << L"New X Pos: " << player.XPos() << std::endl;
        std::wcout << L"New Y Pos: " << player.YPos() << std::endl;
    }
    return true;
}