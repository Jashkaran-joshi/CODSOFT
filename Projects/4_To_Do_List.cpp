#include <iostream>
#include <conio.h> // For _getch() 
#include <string> // For handling string
using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks

struct Task // Task structure to store task details
{
    string description;
    bool completed;
};

void jumpMenu() // For bottom
{
    cout << "\nPress any key to continue...";
    _getch();
}

void heading() // For heading
{
    system("cls");
    cout << "\n";
    cout << "//////////-----To-Do List Manager-----//////////\n\n\n";
}

void displayMenu() // For displaying menu
{
    heading();
    cout << "Menu:\n";
    cout << "\t1. Add Task\n";
    cout << "\t2. View Tasks\n";
    cout << "\t3. Mark Task as Completed\n";
    cout << "\t4. Remove Task\n";
    cout << "\t5. Exit\n";
    cout << "\nEnter your choice: ";
}

void addTask(Task tasks[], int &taskCount) // For adding task
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "\nTask list is full. Cannot add more tasks.\n";
        jumpMenu();
        return;
    }

    Task newTask;
    cout << "\nEnter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks[taskCount] = newTask;
    taskCount++;
    cout << "Task added successfully.\n";
    jumpMenu();
}

void viewTasks(const Task tasks[], int taskCount) // For viewing task
{
    if (taskCount == 0)
    {
        cout << "\nNo tasks available.\n";
        jumpMenu();
        return;
    }

    cout << "\nTasks:\n";
    for (int i = 0; i < taskCount; ++i)
    {
        cout << "\t" << (i + 1) << ". " << tasks[i].description;
        if (tasks[i].completed)
        {
            cout << " (Completed)";
        }
        cout << "\n";
    }
}

void markTaskAsCompleted(Task tasks[], int taskCount) // For marking the task as completed
{
    viewTasks(tasks, taskCount);
    if (taskCount == 0)
    {
        return;
    }

    int taskNumber;
    cout << "\nEnter the task number to mark as completed: ";
    cin >> taskNumber;
    cin.ignore(); // To ignore the newline character left in the input buffer

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "Invalid task number.\n";
        jumpMenu();
        return;
    }

    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed.\n";
    jumpMenu();
}

void removeTask(Task tasks[], int &taskCount) // For removing the task
{
    viewTasks(tasks, taskCount);
    if (taskCount == 0)
    {
        return;
    }

    int taskNumber;
    cout << "\nEnter the task number to remove: ";
    cin >> taskNumber;
    cin.ignore(); // To ignore the newline character left in the input buffer

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "Invalid task number.\n";
        jumpMenu();
        return;
    }

    for (int i = taskNumber - 1; i < taskCount - 1; ++i)
    {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "Task removed successfully.\n";
    jumpMenu();
}

int main()
{
    Task tasks[MAX_TASKS]; // Array to store tasks
    int taskCount = 0;     // Current number of tasks
    int choice;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To ignore the newline character left in the input buffer

        switch (choice)
        {
        case 1:
            addTask(tasks, taskCount);
            break;
        case 2:
            viewTasks(tasks, taskCount);
            jumpMenu();
            break;
        case 3:
            markTaskAsCompleted(tasks, taskCount);
            break;
        case 4:
            removeTask(tasks, taskCount);
            break;
        case 5:
            cout << "\nExiting the program.\n\n";
            break;
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 5.\n";
            jumpMenu();
            break;
        }

    } while (choice != 5);

    return 0;
}
