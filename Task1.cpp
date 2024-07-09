#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void displayBoard()
{
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << "|";
        }
        cout << "\n";
        if (i < 2)
            cout << "  -+-+-\n";
    }
}

bool makeMove(int row, int col)
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
        {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
    {
        return true;
    }
    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame()
{
    initializeBoard();
    bool gameEnded = false;
    while (!gameEnded)
    {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (makeMove(row, col))
        {
            if (checkWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameEnded = true;
            }
            else if (checkDraw())
            {
                displayBoard();
                cout << "The game is a draw!\n";
                gameEnded = true;
            }
            else
            {
                switchPlayer();
            }
        }
        else
        {
            cout << "Invalid move. Try again.\n";
        }
    }
}

int main()
{
    char playAgain = 'y';
    while (playAgain == 'y')
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    return 0;
}