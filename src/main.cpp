#include "row.h"
#include "player.h"

using mes_row::Row;
using mes_player::Player;

void Simulate();

int main()
{
    Row row;
    row.GenerateRows(10);

    std::wcout << L"Press any key to exit..." << std::endl;
    std::cin.get();
    return 0;
}

bool Simulate(Row row, Player player)
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