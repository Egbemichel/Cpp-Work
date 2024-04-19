#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;
const int MAX_NAME_LENGTH = 50;
const int MAX_CONTACT_LENGTH = 20;

class Node
{
public:
    char name[MAX_NAME_LENGTH];
    char contact[MAX_CONTACT_LENGTH];
    Node *next;

    Node(const char *newName, const char *newContact) : next(nullptr)
    {
        strncpy(name, newName, MAX_NAME_LENGTH - 1);
        name[MAX_NAME_LENGTH - 1] = '\0';
        strncpy(contact, newContact, MAX_CONTACT_LENGTH - 1);
        contact[MAX_CONTACT_LENGTH - 1] = '\0';
    }
};

class AddressBook
{
private:
    Node *head;

public:
    AddressBook() : head(nullptr) {}

    ~AddressBook()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
    void menu()
    {
        cout << "*****************************************************************" << endl;
        cout << "*                       ADDRESS BOOK                            *" << endl;
        cout << endl;
        cout << "*****************************************************************" << endl;
        cout << "1   ADD CONTACT                                      " << " + " << endl;
        cout << "*****************************************************************" << endl;
        cout << "2   SEARCH CONTACT                                   " << " o- " << endl;
        cout << "*****************************************************************" << endl;
        cout << "3   DELETE CONTACT                                   " << " - " << endl;
        cout << "*****************************************************************" << endl;
        cout << "4   VIEW CONTACTS                                    " << " oo" << endl;
        cout << "*****************************************************************" << endl;
        cout << "5   EXIT                                             " << " X " << endl;
        cout << "*****************************************************************" << endl;
    }

    void addContact()
    {
        char name[MAX_NAME_LENGTH];
        char contact[MAX_CONTACT_LENGTH];

        cout << "***********************************************" << endl;
        cout << "                      |                " << endl;
        cout << "        ______________|______________ " << endl;
        cout << "                      |                " << endl;
        cout << "***********************************************" << endl;
        cout << "Enter name: ";
        cin.getline(name, MAX_NAME_LENGTH);
        while (!isValidName(name))
        {
            cout << "Invalid name. Please enter again: " << endl;
            cin.getline(name, MAX_NAME_LENGTH);
        }

        cout << "Enter contact: ";
        cin.getline(contact, MAX_CONTACT_LENGTH);
        while (!isValidContact(contact))
        {
            cout << "Invalid contact. Please enter again: " << endl;
            cin.getline(contact, MAX_CONTACT_LENGTH);
        }

        Node *current = head;
        while (current != nullptr)
        {
            if (strcmp(current->contact, contact) == 0)
            {
                cout << "*************************************************************\n";
                cout << "*   CONTACT WITH PHONE NUMBER: " << contact << " ALREADY EXISTS *\n";
                cout << "*************************************************************\n";
                return;
            }
            current = current->next;
        }

        Node *newNode = new Node(name, contact);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            Node *prev = nullptr;
            while (current != nullptr && strcmp(current->name, name) < 0)
            {
                prev = current;
                current = current->next;
            }
            if (prev == nullptr)
            {
                head = new Node(name, contact);
                head->next = current;
            }
            else
            {
                prev->next = new Node(name, contact);
                prev->next->next = current;
            }
        }
        cout << "**********************************************************\n";
        cout << "*             CONTACT SUCCESSFULLY ADDED                 *\n";
        cout << "**********************************************************\n";
        printBook();
    }
    bool isValidName(const char *name)
    {
        for (int i = 0; name[i] != '\0'; ++i)
        {
            if (!isalpha(name[i]) && !isspace(name[i]))
            {
                return false;
            }
        }
        return true;
    }

    bool isValidContact(const char *contact)
    {
        for (int i = 0; contact[i] != '\0'; ++i)
        {
            if (!isdigit(contact[i]))
            {
                return false;
            }
        }
        return true;
    }

    void printContactsByName(const char *name)
    {
        Node *current = head;
        int index = 1;
        while (current != nullptr)
        {
            if (strcmp(current->name, name) == 0)
            {
                cout << index << ". Name: " << current->name << " Contact: " << current->contact << endl;
                index++;
            }
            current = current->next;
        }
    }

    void searchContact(const char *name)
    {
        if (isEmpty())
        {
            cerr << "***************************************************\n";
            cerr << "*            ADDRESS BOOK IS EMPTY.               *\n";
            cerr << "***************************************************\n";
            return;
        }

        bool found = false; // Flag to track if any contacts with the given name were found

        // Display all contacts with the given name
        Node *current = head;
        while (current != nullptr)
        {
            if (strcmp(current->name, name) == 0)
            {
                if (!found)
                {

                    cout << "*************************************************************\n";
                    cout << "*                      CONTACT(S)                           *\n";
                    cout << "*************************************************************\n";
                    found = true;
                }
                cout << "Name: " << current->name << " Contact: " << current->contact << endl;
            }
            current = current->next;
        }

        // Display message if no contacts with the given name were found
        if (!found)
        {

            cout << "*************************************************************\n";
            cout << "*                CONTACT NOT FOUND                          *\n";
            cout << "*************************************************************\n";
        }
    }

    void deleteContact(const char *name)
    {
        if (head == nullptr)
        {
            cerr << "***************************************************\n";
            cerr << "*     ADDRESS BOOK IS EMPTY.NOTHING TO DELETE     *\n";
            cerr << "***************************************************\n";
            return;
        }

        // Count the number of contacts with the given name
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            if (strcmp(current->name, name) == 0)
            {
                count++;
            }
            current = current->next;
        }

        // If there's only one contact with the given name, delete it directly
        if (count == 1)
        {
            Node *current = head;
            Node *prev = nullptr;
            while (current != nullptr)
            {
                if (strcmp(current->name, name) == 0)
                {
                    if (prev == nullptr)
                    {
                        head = current->next;
                    }
                    else
                    {
                        prev->next = current->next;
                    }
                    delete current;
                    cout << "**********************************************************\n";
                    cout << "*             CONTACT SUCCESSFULLY DELETED               *\n";
                    cout << "**********************************************************\n";
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
        // If there are multiple contacts with the given name, ask the user to select which one to delete
        else if (count > 1)
        {
            int choice;
            cout << "**********************************************************\n";
            cout << "Contacts with name '" << name << "':\n";
            cout << "**********************************************************\n";
            printContactsByName(name); // Helper function to print contacts with the given name
            cout << "Which contact do you wish to delete?(1 / 2 /...): ";
            cin >> choice;
            while (choice < 1 || choice > count)
            {
                cout << "Invalid choice. Please enter a number between 1 and " << count << ": ";
                cin >> choice;
            }

            // Delete the selected contact
            int index = 1;
            Node *current = head;
            Node *prev = nullptr;
            while (current != nullptr)
            {
                if (strcmp(current->name, name) == 0)
                {
                    if (index == choice)
                    {
                        if (prev == nullptr)
                        {
                            head = current->next;
                        }
                        else
                        {
                            prev->next = current->next;
                        }
                        delete current;
                        cout << "**********************************************************\n";
                        cout << "*             CONTACT SUCCESSFULLY DELETED               *\n";
                        cout << "**********************************************************\n";
                        return;
                    }
                    index++;
                }
                prev = current;
                current = current->next;
            }
        }

        cout << "**********************************************************\n";
        cout << "*                  CONTACT NOT FOUND                     *\n";
        cout << "**********************************************************\n";
    }

    void printBook()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << "NAME: " << current->name << setw(20) << "CONTACT: " << current->contact << endl;
            current = current->next;
        }
    }
};

int main()
{
    AddressBook addressBook;

    char choice;
    char name[MAX_NAME_LENGTH];

    do
    {
        addressBook.menu();
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice)
        {
        case '1':
            system("cls");
            addressBook.addContact();
            break;
        case '2':
            system("cls");
            cout << "Enter name to search: ";
            cin.getline(name, MAX_NAME_LENGTH);
            addressBook.searchContact(name);
            break;
        case '3':
            system("cls");
            cout << "Enter name to delete: ";
            cin.getline(name, MAX_NAME_LENGTH);
            addressBook.deleteContact(name);
            break;
        case '4':
            system("cls");
            cout << "*****************************************************************" << endl;
            cout << "*                       ADDRESS BOOK                            *" << endl;
            cout << endl;
            addressBook.printBook();
            break;
        case '5':
            system("cls");
            cout << "\nExiting program..." << endl;
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
