#include <iostream>
using namespace std;

void heading() // For heading
{
    system("cls");
    cout << "\n";
    cout << "//////////-------Simple Calculator------//////////\n\n\n";
}

int main()
{
    double num1, num2;
    char operation, restartAgain;

    do
    {
        heading();

        cout << "Enter the first number   :-  ", cin >> num1;
        cout << "Enter the second number  :-  ", cin >> num2;

        cout << "\nEnter the operation (+, -, *, /)  :-  ", cin >> operation;

        switch (operation)
        {
        case '+':
            cout << "\n\nResult  :-  " << num1 + num2 << endl
                 << endl;
            break;
        case '-':
            cout << "\n\nResult  :-  " << num1 - num2 << endl
                 << endl;
            break;
        case '*':
            cout << "\n\nResult  :-  " << num1 * num2 << endl
                 << endl;
            break;
        case '/':
            if (num2 != 0)
            {
                cout << "\n\nResult  :-  " << num1 / num2 << endl
                     << endl;
            }
            else
            {
                cout << "\n\nError: Division by zero is not allowed." << endl
                     << endl;
            }
            break;
        default:
            cout << "\n\nError: Invalid operation." << endl
                 << endl;
            break;
        }

        cout << "Do you want to restart it again? (Y/N): ";
        cin >> restartAgain;

    } while (restartAgain == 'Y' || restartAgain == 'y');
    return 0;
}
