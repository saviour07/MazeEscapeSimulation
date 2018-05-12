#include <string>
#include <iostream>
#include "row.h"
#include "player.h"

void Simulate();

int main()
{
    mes_row::Row row;
    row.GenerateRows(10);
    for (int i = 0; i < 10; ++i)
    {
        std::wcout << row.GetDirection(i).DirectionName() << std::endl;
    }

    std::wcout << L"Press any key to exit..." << std::endl;
    std::cin.get();
    return 0;
}

bool Simulate(mes_row::Row row, mes_player::Player player)
{
   while (true)
    {
        // Get the players current position
        const auto currentPosition = player.GetCurrentPosition();
        if (row.IsOutsideMaze(currentPosition))
        {
            return true;
        }

        // Get the direction of the square the player is on
        const auto direction = row.GetDirection(currentPosition);

        // Move the player in the direction the square is pointing
        player.MoveDirection(direction);

        // Change the direction of the square the player was previously on
        row.UpdateDirection(currentPosition);
    }
}