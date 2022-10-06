#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void printBoard(char board[10])
{
    printf("\n   0 1 2\n   - - -\n");

    for (int y = 0; y < 3; y++)
    {
        printf("%d ", y);
        for (int x = 0; x < 3; x++)
        {
            printf("|%c", board[y * 3 + x]);
        }

        printf("|\n   - - -\n");
    }
}

int main()
{
    // prompt for play mode
    char playMode[2];
    int players;
    printf("Enter\n\t1\tif you want to play against a bot\n\t2\tif you want to play against another person\n");
    do
    {
        gets(playMode);
        players = atoi(playMode);
    } while (players != 1 && players != 2);
    // display game board
    char board[10] = "         ";
}