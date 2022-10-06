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

bool checkWin(char board[10], int y, int x)
{
    bool win = false;

    // checking if all chars in a column are identical
    if (board[x] == board[x + 3] && board[x] == board[x + 6])
    {
        win = true;
    } // checking rows
    else if (board[y * 3] == board[y * 3 + 1] && board[y * 3] == board[y * 3 + 2])
    {
        win = true;
    } // checking upper left to bottom right diagonal ([0, 0] to [2, 2])
    else if (x == y && board[0] == board[4] && board[0] == board[8])
    {
        win = true;
    } // checking upper right to bottom left diagonal ([2, 0] to [0, 2])
    else if (x + y == 2 && board[2] == board[4] && board[2] == board[6])
    {
        win = true;
    }

    return win;
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
    printBoard(board);
    bool gameComplete = false;

    for (int i = 0; i < 5; i++)
    {
        int xCoord1;
        int yCoord1;

        // asks p1 for coords until valid and empty coords are given
        do
        {
            printf("Player 1 move x coord: ");
            char xCoord[2];
            gets(xCoord);
            xCoord1 = atoi(xCoord);

            printf("Player 1 move y coord: ");
            char yCoord[2];
            gets(yCoord);
            yCoord1 = atoi(yCoord);
        } while (xCoord1 < 0 || xCoord1 > 2 || yCoord1 < 0 || yCoord1 > 2 || board[yCoord1 * 3 + xCoord1] != ' ');
        // fills in chosen spot
        board[yCoord1 * 3 + xCoord1] = 'X';
        printBoard(board);
        if (checkWin(board, yCoord1, xCoord1))
        {
            printf("PLAYER 1 WINS!!\n");
            gameComplete = true;
            break;
        }

        int xCoord2;
        int yCoord2;

        do
        {
            if (players == 2)
            {
                printf("Player 2 move x coord: ");
                char xCoord[2];
                gets(xCoord);
                xCoord2 = atoi(xCoord);

                printf("Player 2 move y coord: ");
                char yCoord[2];
                gets(yCoord);
                yCoord2 = atoi(yCoord);
            }
            else
            {
                srand(time(NULL));
                xCoord2 = rand() % 3;
                yCoord2 = rand() % 3;
            }

        } while (xCoord2 < 0 || xCoord2 > 2 || yCoord2 < 0 || yCoord2 > 2 || board[yCoord2 * 3 + xCoord2] != ' ');

        board[yCoord2 * 3 + xCoord2] = 'O';
        printBoard(board);
        if (checkWin(board, yCoord2, xCoord2))
        {
            printf("PLAYER 2 WINS!!\n");
            gameComplete = true;
            break;
        }
    }
}