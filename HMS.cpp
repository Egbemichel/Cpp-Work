#include <iostream>
#include <cctype>
#include <cstring>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;
// maximim number of rooms
const int MAX_ROOMS = 100;

// class Customer with all the customer objects
class Customer
{
public:
    string name;
    string address;
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    int booking_id;
    string currency;
};
// room class with all the rooms classes
class Room
{
public:
    int roomNumber;
    char ac;
    char pool;
    char canBar;
    string currency;
    int rent;
    int status;

    class Customer cust;
    class Room addRoom(int);
    void searchRoom(int);
    void displayRoom(Room);
};
// Global variable decleraion(not a good practice)
class Room rooms[MAX_ROOMS];
int roomCount = 0;

// admin class inheriting from room class
class admin : protected Room
{
public:
    void checkIn();
    void searchCustomer(string);
    void AvailRoom();
    void checkOut(int);
    void checkoutInfo();
    void manageRooms();
};
// utility function declarations to clear buffer and display headers
void clearInputBuffer();
void displayHeader(const string &);

Room Room::addRoom(int rno)
{
    class Room room;
    room.roomNumber = rno;
    // Error handling i.e while()
    while (true)
    {
        cout << "\nType AC (Y/N): ";
        if (!(cin >> room.ac) || (room.ac != 'Y' && room.ac != 'y' && room.ac != 'N' && room.ac != 'n'))
        {
            cout << "Invalid input, please try again";
            clearInputBuffer();
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "\nType pool (Y/N): ";
        if (!(cin >> room.pool) || (room.pool != 'Y' && room.pool != 'y' && room.pool != 'N' && room.pool != 'n'))
        {
            cout << "Invalid input, please try again";
            clearInputBuffer();
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "\nType Candy Bar (Y/N): ";
        if (!(cin >> room.canBar) || (room.canBar != 'Y' && room.canBar != 'y' && room.canBar != 'N' && room.canBar != 'n'))
        {
            cout << "Invalid input, please try again";
            clearInputBuffer();
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "\nDaily rent: ";
        if (!(cin >> room.rent) || room.rent <= 0)
        {
            cout << "Invalid input. Please enter a valid rent.\n";
            clearInputBuffer();
        }
        else
        {
            break;
        }
    }
    cout << "\nEnter Currency you would like to use to make payments (e.g., USD, EUR): ";
    cin >> room.currency;
    room.status = 0;

    cout << "Room Added Successfully";

    return room;
}

void Room::searchRoom(int rno)
{

    int i, found = 0;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            if (rooms[i].status == 1)
            {
                cout << "\n Room is Reserved";
            }
            else
            {
                cout << "Room is available\n";
                cout << "Room Details\n\n";
                displayRoom(rooms[i]);
            }
        }
    }
    if (found == 0)
    {
        cout << "\nRoom NOT Found";
    }
}

void Room::displayRoom(Room tempRoom)
{
    displayHeader(" Room Details ");
    cout << "\n Room Number: " << tempRoom.roomNumber;
    cout << "\n Specifications "
         << "\n AC: " << tempRoom.ac << "\n Pool: " << tempRoom.pool << "\n Candy Bar: " << tempRoom.canBar;
    cout << "\n Daily Rent: " << tempRoom.currency << tempRoom.rent;
}

void admin::checkoutInfo()
{
    if (roomCount == 0)
    {
        cout << "No Guest in Hotel";
    }
    for (int i = 0; i < roomCount; i++)
    {
        if (rooms[i].status == 1)
        {
            cout << "\nCustomer's Name: " << rooms[i].cust.name;
            cout << "\nRoom number: " << rooms[i].roomNumber;
            cout << "\nCustomer's Address: " << rooms[i].cust.address;
            cout << "\nCustomer's Phone: " << rooms[i].cust.phone << endl;
            cout << "-----------------------------------------------------------------------";
        }
    }
}

void admin::checkIn()
{
    int i, found = 0, rno;
    class Room room;
    cout << "Enter Room number: ";
    cin >> rno;

    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            if (rooms[i].status == 1)
            {
                cout << "\n Room is Already Booked";
                return;
            }

            while (true)
            {
                cout << "\nEnter booking ID: ";
                if (!(cin >> rooms[i].cust.booking_id) || rooms[i].cust.booking_id <= 0)
                {
                    cout << "Invalid input. Please enter a valid booking ID.\n";
                    clearInputBuffer();
                }
                else
                {
                    break;
                }
            }
            clearInputBuffer();
            cout << "\nEnter Customer Name: ";
            getline(cin, rooms[i].cust.name);                                                                       // gets a line of characters including spaces
            transform(rooms[i].cust.name.begin(), rooms[i].cust.name.end(), rooms[i].cust.name.begin(), ::tolower); // converts the input to lowercase to ease searchCustomer function
            clearInputBuffer();

            cout << "\nEnter Address: ";
            getline(cin, rooms[i].cust.address);                                                                             // gets a line of characters including spaces
            transform(rooms[i].cust.address.begin(), rooms[i].cust.address.end(), rooms[i].cust.address.begin(), ::tolower); ////converts the input to lowercase to ease searchCustomer function

            cout << "\nEnter Phone: ";
            cin >> rooms[i].cust.phone;

            cout << "\nEnter From date: ";
            cin >> rooms[i].cust.from_date;

            cout << "\n Enter To Date: ";
            cin >> rooms[i].cust.to_date;
            // Error handling
            while (true)
            {
                cout << "Enter Advanced Payment: ";
                if (!(cin >> rooms[i].cust.payment_advance) || rooms[i].cust.payment_advance <= 0)
                {
                    cout << "Invalid input. Please enter a valid advanced payment.\n";
                    clearInputBuffer();
                }
                else
                {
                    break;
                }
            }

            cout << "\n Please Enter a currency for payments: ";
            cin >> rooms[i].currency;

            rooms[i].status = 1;

            cout << "Customer Checked-in Successfully..";
        }
    }
}

void admin::AvailRoom()
{
    int i, found = 0;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].status == 0)
        {
            displayRoom(rooms[i]);
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "All Rooms are reserved.";
    }
}

void admin::searchCustomer(string pname)
{
    int i, found = 0;

    // Convert pname to lowercase for case-insensitive comparison
    transform(pname.begin(), pname.end(), pname.begin(), ::tolower);

    for (i = 0; i < roomCount; i++)
    {
        // Convert the customer name to lowercase for case-insensitive comparison
        string custNameLower = rooms[i].cust.name;
        transform(custNameLower.begin(), custNameLower.end(), custNameLower.begin(), ::tolower);

        if (rooms[i].status == 1 && custNameLower == pname)
        {
            cout << "\nCustomer Name: \t" << rooms[i].cust.name;
            cout << "\nRoom Number: \t" << rooms[i].roomNumber;
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Person NOT found,\n";
    }
}

void admin::checkOut(int roomNum)
{
    int i, found = 0, days, rno;
    float billAmt = 0;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)
        {
            found = 1;
            break;
        }
        else if (rooms[i].status == 0)
        {
            cout << "Room is Empty, Check-in someone First ";
            break;
        }
        else if (rooms[i].roomNumber != roomNum)
        {
            cout << "Room Number NOT Found";
            break;
        }
    }
    if (found == 1)
    {
        cout << "Enter Number of Days:\t";
        cin >> days;
        billAmt = days * rooms[i].rent;

        cout << "*************** Checkout Details ***************";
        cout << "\nCustomer Name: " << rooms[i].cust.name;
        cout << "\nRoom Number: " << rooms[i].roomNumber;
        cout << "\nAddress: " << rooms[i].cust.address;
        cout << "\nPhone: " << rooms[i].cust.phone;
        cout << "\nTotal Amount due: " << rooms[i].currency << billAmt;
        cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance;
        cout << "\nTotal Payable: " << billAmt - rooms[i].cust.payment_advance;

        rooms[i].status = 0;
    }
}

void admin::manageRooms()
{
    class Room room;
    int op, rno, pro = 0;

    do
    {
        displayHeader(" Manage Rooms ");
        cout << "\n1. Add Room";
        cout << "\n2. Search Room";
        cout << "\n3. Go Back to Main Menu";
        cout << "\nEnter option: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "\nEnter Room Number: ";
            cin >> rno;
            pro = 0;
            for (int i = 0; i < roomCount; i++)
            {
                if (rooms[i].roomNumber == rno)
                {
                    pro = 1; // checks if the room with that room number already exists
                    break;
                }
            }
            if (pro == 1)
            {
                cout << "\nRoom Number is Present.\nPlease enter a unique Number";
            }
            else
            {
                rooms[roomCount] = rooms[roomCount].addRoom(rno);
                roomCount++;
            }
            break;

        case 2:
            cout << "Enter Room Number: ";
            cin >> rno;
            room.searchRoom(rno);
            break;

        case 3:
            return;

        default:
            cout << "\nPlease Enter Correct option";
            break;
        }
    } while (op != 3);
}

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayHeader(const string &title)
{
    cout << "\n****" << title << "****" << endl;
}

int main()
{
    class admin man;
    int op;
    string pname;
    int rno;

    do
    {
        displayHeader(" EMPIRIAL HOTEL AND RESORTS ");
        cout << "\n1. Manage Rooms";
        cout << "\n2. Check-in Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Customer";
        cout << "\n5. Checkout Room";
        cout << "\n6. Checkout Information(customers still to check out)";
        cout << "\n7. Exit";
        cout << "\n\n Enter option: ";
        cin >> op;

        switch (op)
        {
        case 1:
            man.manageRooms();
            break;

        case 2:
            if (roomCount == 0)
            {
                cout << "\nRoom data is NOT Available.\n Please add the rooms first.";
            }
            else
            {
                man.checkIn();
            }
            break;

        case 3:
            if (roomCount == 0)
            {
                cout << "\nRooms data is NOT available.\nPlease add the rooms first";
            }
            else
            {
                man.AvailRoom();
                break;
            }
        case 4:
            if (roomCount == 0)
            {
                cout << "\nRooms data is NOT available.\nPlease add the rooms first";
            }
            else
            {
                clearInputBuffer(); // Clear input buffer before reading the customer name
                cout << "Enter Customer Name: ";
                getline(cin, pname); // Use getline to read the entire line
                man.searchCustomer(pname);
            }
            break;

        case 5:
            if (roomCount == 0)
            {
                cout << "\nRooms are NOT available.\nPlease add the rooms first";
            }
            else
            {
                cout << "Enter Room Number: ";
                cin >> rno;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid room number." << endl;
                    continue;
                }
                man.checkOut(rno);
            }
            break;

        case 6:
            man.checkoutInfo();
            break;

        case 7:
            cout << "\nTHANK YOU FOR USING OUR SOFTWARE\n";
            break;

        default:
            cout << "Please Enter Correct option";
            break;
        }
    } while (op != 7);

    return 0;
}
