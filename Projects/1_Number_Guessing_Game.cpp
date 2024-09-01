#include <iostream>
#include <conio.h> // For _getch()
#include <cstdlib> // For rand() , srand() , system()
#include <ctime>   // For time()
using namespace std;

void heading() // For heading
{
    cout << "\n";
    cout << "//////////-----Number Guessing Game-----//////////\n\n\n";
}

void clear() // For clear console screen by taking character from user
{
    cout << "\nPress any Key to continue.....  ";
    _getch();
    system("cls");
}

int main()
{
    int rangeStart, rangeEnd;

    system("cls");

    heading();
    cout << "\t\tLet's Play a game!\n\n";
    cout << "In which you will give me the range of number from\nwhich i have to choose a number then you have to\nguess the number.\n\n\n";
    clear();

    heading();
    cout << "Now give the range of the number.\n\n";
    cout << "Starting Point  -  ", cin >> rangeStart;
    cout << "Ending Point    -  ", cin >> rangeEnd;
    cout << endl;
    clear();

    srand(static_cast<unsigned>(time(0))); // Initialize random number generator

    int randomNumber = rand() % (rangeEnd - rangeStart + 1) + rangeStart; // Generate a random number between the user-defined range

    int userGuess = 0;
    bool correctGuess = false;
    int count = 1;

    heading();

    while (!correctGuess)
    {
        cout << "Enter your " << count << " guess: ";
        cin >> userGuess;

        if (userGuess < randomNumber)
        {
            cout << "\t\t\tToo low! Try again.\n\n";
        }
        else if (userGuess > randomNumber)
        {
            cout << "\t\t\tToo high! Try again.\n\n";
        }
        else
        {
            cout << "\t\t\tCongratulations! You've guessed the correct number!\n\n";
            correctGuess = true;
        }

        count++;
    }

    _getch();

    return 0;
}
