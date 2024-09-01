#include <iostream> 
#include <conio.h> // For _getch()
#include <string> // For handling string

using namespace std;

void jumpMenu() // For bottom
{
    cout << "\nPress any key to continue...";
    _getch();
}

class Book // For maintaining all books detail in a class
{
public:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    Book(string t = "", string a = "", string i = "", bool available = true)
        : title(t), author(a), ISBN(i), isAvailable(available) {}

    void display() const // For displaying the book detail
    {
        cout << "\nTitle: " << title << ",   Author: " << author << ",   ISBN: " << ISBN
             << ",   Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Library // For maintaining all function which can be performed on books in a class
{
private:
    static const int MAX_BOOKS = 100; // Maximum number of books
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const Book &book) // For prompt after entering book details
    {
        if (bookCount < MAX_BOOKS)
        {
            books[bookCount++] = book;
            cout << "\nBook added successfully." << endl;
            jumpMenu();
        }
        else
        {
            cout << "\nLibrary is full. Cannot add more books." << endl;
            jumpMenu();
        }
    }

    void searchBook(const string &query) const // For searching of book and print using display() function
    {
        int count = 0;
        for (int i = 0; i < bookCount; ++i)
        {
            if (books[i].title == query || books[i].author == query || books[i].ISBN == query)
            {
                books[i].display();
                count++;
            }
        }
        if (count == 0)
        {
            cout << "\nBook not found!" << endl;
        }
        jumpMenu();
        return;
    }

    void checkoutBook(const string &ISBN) // For checkout a book
    {
        for (int i = 0; i < bookCount; ++i)
        {
            if (books[i].ISBN == ISBN)
            {
                if (books[i].isAvailable)
                {
                    books[i].isAvailable = false;
                    cout << "\nBook checked out successfully." << endl;
                }
                else
                {
                    cout << "\nBook is not available." << endl;
                }
                jumpMenu();
                return;
            }
        }
        cout << "\nBook not found!" << endl;
        jumpMenu();
    }

    void returnBook(const string &ISBN) // For return a book
    {
        for (int i = 0; i < bookCount; ++i)
        {
            if (books[i].ISBN == ISBN)
            {
                if (!books[i].isAvailable)
                {
                    books[i].isAvailable = true;
                    cout << "\nBook returned successfully." << endl;
                }
                else
                {
                    cout << "\nBook was not checked out." << endl;
                }
                jumpMenu();
                return;
            }
        }
        cout << "\nBook not found!" << endl;
        jumpMenu();
    }

    void displayAllBooks() const // For displaying all the list of books all their in the program using display() function
    {
        if (bookCount == 0)
        {
            cout << "\nNo books available." << endl;
            jumpMenu();
            return;
        }
        for (int i = 0; i < bookCount; ++i)
        {
            books[i].display();
        }
        jumpMenu();
    }

    double calculateFine(int daysOverdue) const // For calculating the fine for book over day
    {
        const double finePerDay = 5;
        return daysOverdue * finePerDay;
    }
};

void heading() // For heading
{
    system("cls");
    cout << "\n";
    cout << "//////////-----Library Management System-----//////////\n\n\n";
}

void menu() // For displaying menu
{
    heading();
    cout << "Menu:" << endl;
    cout << "\t1. Add Book" << endl;
    cout << "\t2. Search Book" << endl;
    cout << "\t3. Checkout Book" << endl;
    cout << "\t4. Return Book" << endl;
    cout << "\t5. Display All Books" << endl;
    cout << "\t6. Calculate Fine" << endl;
    cout << "\t7. Exit" << endl;
}

int main()
{
    Library library;
    int choice;
    string title, author, ISBN;
    int daysOverdue;

    while (true)
    {
        menu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            library.addBook(Book(title, author, ISBN));
            break;
        case 2:
            cout << "Enter title/author/ISBN to search: ";
            cin.ignore();
            getline(cin, title);
            library.searchBook(title);
            break;
        case 3:
            cout << "Enter ISBN to checkout: ";
            cin.ignore();
            getline(cin, ISBN);
            library.checkoutBook(ISBN);
            break;
        case 4:
            cout << "Enter ISBN to return: ";
            cin.ignore();
            getline(cin, ISBN);
            library.returnBook(ISBN);
            break;
        case 5:
            cout << "List of all books: " << endl;
            library.displayAllBooks();
            break;
        case 6:
            cout << "Enter number of overdue days: ";
            cin >> daysOverdue;
            cout << "\nFine amount(In Rupees): " << library.calculateFine(daysOverdue) << endl;
            jumpMenu();
            break;
        case 7:
            cout << "Exiting the program.\n\n";
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
            jumpMenu();
        }
    }
}
