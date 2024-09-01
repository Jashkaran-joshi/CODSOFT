#include <iostream>
#include <conio.h> // For _getch()
using namespace std;

void heading() // For heading
{
    system("cls");
    cout << "\n";
    cout << "//////////-----Tic Tac Toe Game-----//////////\n\n\n";
}

void printBoard(const char board[3][3]) // For printing board
{
    heading();
    for (int i = 0; i < 3; ++i)
    {
        cout << "\t\t  ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "\t\t  --|---|--" << endl;
        }
    }
}

bool isValidMove(int move, const char board[3][3]) // For check valid input
{
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (move >= 1 && move <= 9 && board[row][col] == ' ')
    {
        return true;
    }
    return false;
}

bool checkWin(const char board[3][3], char player) // For check wining by comparing player sign and array
{
    // Check rows and columns horizontal and vertical
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool checkDraw(const char board[3][3]) // For check draw by comparing player sign and array
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void playTicTacToe()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    bool gameWon = false;

    while (true)
    {
        printBoard(board);
        int move;
        cout << "\n\n\t\t   Player " << currentPlayer << "\n\t    Enter your move (1-9): ";
        cin >> move;

        if (isValidMove(move, board))
        {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer))
            {
                printBoard(board);
                cout << "\n\n\t\tPlayer " << currentPlayer << " wins!" << endl;
                gameWon = true;
                break;
            }
            if (checkDraw(board))
            {
                printBoard(board);
                cout << "\n\n\t     The game is a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else
        {
            cout << "\n\n     Invalid move, Press enter and try again!." << endl;
            _getch();
        }
    }
}

int main()
{
    char playAgain;
    do
    {
        playTicTacToe();
        cout << "\tDo you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\n\n\t    Thank you for playing!\n\n"
         << endl;

    _getch();
    return 0;
}
