#include <string>
#include <iostream>
#include "player.h"
#include "maze.h"

bool Simulate(mes_maze::Maze& maze, mes_player::Player player);

int main()
{
    mes_maze::Maze maze(10, 10);
    maze.GenerateMaze();

    mes_player::Player player;
    const auto& startPosition = player.StartPosition(maze.RowCount(), maze.ColCount());
    std::wcout << L"Start Y: " << startPosition.Y << std::endl;
    std::wcout << L"Start X: " << startPosition.X << std::endl;

    if (Simulate(maze, player))
    {
        std::wcout << L"Out" << std::endl;
    }

    return 0;
}

bool Simulate(mes_maze::Maze& maze, mes_player::Player player)
{
    int turn = 0;
    while (!player.IsOutsideMaze(maze.Rows))
    {
        std::wcout << L"Turn: " << std::to_wstring(++turn) << std::endl;
        const auto position = player.MoveDirection(maze.Rows);

        std::wcout << L"New Y Pos: " << position.Y << std::endl;
        std::wcout << L"New X Pos: " << position.X << std::endl;
        std::wcout << L"================================" << std::endl;
    }
    return true;
}