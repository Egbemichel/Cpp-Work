#include <iostream>
#include <limits>
#include <cstring>
using namespace std;

const int max_books = 100;

class Customer
{

public:
    char name[20];
    char phone[12];
    char from_date[12];
};

class Book
{
public:
    int bookId;
    char bookTitle[100];
    char bookAuthor[20];
    int status;

    class Customer cust;
    class Book addBook(int);
    void searchBook(int);
    void displayBook(Book);
};
class Book books[max_books];
int count = 0;

void clearinputBuffer();
void displayHeader(const string &);

class admin : protected Book
{
public:
    void manageBooks();
    void borrowBook();
    void returnBook(int);
    void availBooks();
    void searchCustomer(char *);
};
void admin::manageBooks()
{
    int op, pro = 0, bno;
    class Book book;
    do
    {
        displayHeader("Manage Books");
        cout << "1. Add Books" << endl;
        cout << "2. Search book" << endl;
        cout << "3. Return to main menu" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Enter Book ID:" << endl;
            cin >> bno;
            for (int i = 0; i < count; i++)
            {
                if (books[i].bookId == bno)
                {
                    pro = 1;
                    break;
                }
            }
                if (pro == 1)
                {
                    cout << "Book with ID: " << bno << "is already in your Library, Please enter a unique book ID" << endl;
                }
                else
                {
                    books[count] = books[count].addBook(bno);
                    count++;
                }
                break;
            case 2:
                cout << "Enter Book ID:" << endl;
                cin >> bno;
                book.searchBook(bno);
                break;
            
        case 3:
            return;

        default:
            cout << "Incorrect Entry\n Please Try Again" << endl;
            break;
        }

    } while (op != 3);
}

Book Book::addBook(int bno)
{
    class Book book;
    book.bookId = bno;
    cout << "Book Title: " << endl;
    cin >> bookTitle;
    clearinputBuffer();
    cout << "Book Author: " << endl;
    cin >> bookAuthor;
    clearinputBuffer();

    book.status = 0;
    cout << "Book Added Successfully" << endl;
    return book;
}

void Book::searchBook(int bno)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (books[i].bookId == bno)
        {
            found = 1;
            if (books[i].status == 1)
            {
                cout << "Book is in use" << endl;
            }
            else
            {
                cout << "Book is availabe" << endl;
                cout << "Book Details" << endl;
                displayBook(books[i]);
            }
        }
    }
    if (found == 0)
    {
        cout << "Book NOT Found" << endl;
    }
}

void admin::borrowBook()
{
    class Book book;
    int i, found = 0, bno;
    for (i = 0; i < count; i++)
    {
        if (books[i].bookId == bno)
        {
            found = 1;
            if (books[i].status == 1)
            {
                cout << "Book is in use" << endl;
                return;
            }

            while (true)
            {
                cout << "Enter a Booking ID:" << endl;
                if (!(cin >> books[i].bookId) || books[i].bookId <= 0)
                {
                    cout << "Invalid Input\n Please Enter Valid Book ID" << endl;
                    clearinputBuffer();
                }
                else
                {
                    break;
                }
            }
            cout << "Enter Customer name: " << endl;
            cin >> books[i].cust.name;
            clearinputBuffer();
            cout << "Enter Customer contact: " << endl;
            cin >> books[i].cust.phone;
            cout << "Enter date of possession: " << endl;
            cin >> books[i].cust.from_date;

            books[i].status = 1;

            cout << "Your request has been accepted" << endl;
        }
    }
}

void admin::returnBook(int bno)
{

    int i, found = 0, days;
    for (i = 0; i < count; i++)
    {
        if (books[i].status == 1 && books[i].bookId == bno)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "Enter number of days: " << endl;
        cin >> days;
        cout << "Return Details" << endl;
        cout << "****************************************" << endl;
        cout << "Book Title: " << books[i].bookTitle << endl;
        cout << "Author: " << books[i].bookAuthor << endl;
        cout << "Customer Name: " << books[i].cust.name << endl;
        cout << "Customer Contact: " << books[i].cust.phone << endl;
        cout << "Duration: " << books[i].cust.name << " possessed this book for " << days << " Days,"
             << " From" << books[i].cust.from_date << endl;

        books[i].status = 0;
    }
}

void admin::availBooks()
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (books[i].status = 0)
        {
            displayBook(books[i]);
            found = 1;
        }
    }
    if (found == 1)
    {
        cout << "All Books are in Use: " << endl;
    }
}

void admin::searchCustomer(char *pname)
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (books[i].status == 1 && strcmp(books[i].cust.name, pname) == 0)
        {
            cout << "\nCustomer Name: \t" << books[i].cust.name;
            cout << "\nBook ID: \t" << books[i].bookId;
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Person NOT found,\n";
    }
}

void Book::displayBook(Book temp)
{
    displayHeader(" Room Details ");
    cout << "\n Book ID: " << temp.bookId;
    cout << "\n Specifications "
         << "\n Title: " << temp.bookTitle;
    cout << "\n Author: " << temp.bookAuthor;
}

int main()
{
    class admin man;
    int op;
    do
    {
        displayHeader(" LIBRARY MANAGEMENT SYSTEM ");
        cout
            << "****************************************" << endl;
        cout << "1. Manage Books" << endl;
        cout << "2. Available Books" << endl;
        cout << "3. Search for a Book" << endl;
        cout << "4. Borrow Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter option" << endl;
        cin >> op;

        switch (op)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        default:

            cout << "Incorect Entry\n Please Try Again" << endl;
            break;
        }
    } while (op != 6);

    return 0;
}
void clearinputBuffer()
{
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void displayHeader(const string &title)
{
    cout << "\n****" << title << "****" << endl;
}