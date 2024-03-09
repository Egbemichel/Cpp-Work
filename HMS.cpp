#include <iostream>
#include <cstring>
#include <limits>

/*Make inputs case insensitive
fix getting multiple names seperated by spaces
Add a dummy bank transaction functionality
Add a funtion to convert currency: Hotel has a standard currency that they convert customer currencies to and both are display on the checkout()
Add an Edit and Delete functions*/

using namespace std;
const int MAX_ROOMS = 100;

class Customer
{
public:
    char name[100];
    char address[100];
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    int booking_id;
    string currency;
};

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
    // void deleteRoom(int);
    void displayRoom(Room);
};
class Room rooms[MAX_ROOMS];
int count = 0;

class admin : protected Room
{
public:
    void checkIn();
    void searchCustomer(char *);
    void AvailRoom();
    void checkOut(int);
    void checkoutInfo();
    void manageRooms();
};

void clearInputBuffer();
void displayHeader(const string &);

Room Room::addRoom(int rno)
{
    class Room room;
    room.roomNumber = rno;

    cout << "\nType AC (Y/N): ";
    cin >> room.ac;
    clearInputBuffer();

    cout << "\n Type pool (Y/N): ";
    cin >> room.pool;

    cout << "\n Type Candy Bar (Y/N): ";
    cin >> room.canBar;

    while (true)
    {
        cout << "\n Daily rent: ";
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
    for (i = 0; i < count; i++)
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
    if (count == 0)
    {
        cout << "No Guest in Hotel";
    }
    for (int i = 0; i < count; i++)
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

    for (i = 0; i < count; i++)
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

            cout << "\nEnter Customer Name: ";
            cin >> rooms[i].cust.name;
            clearInputBuffer();

            cout << "\nEnter Address: ";
            cin >> rooms[i].cust.address;

            cout << "\nEnter Phone: ";
            cin >> rooms[i].cust.phone;

            cout << "\nEnter From date: ";
            cin >> rooms[i].cust.from_date;

            cout << "\n Enter To Date: ";
            cin >> rooms[i].cust.to_date;

            while (true)
            {
                cout << "Enter Advanced Payment: ";
                if (!(cin >> rooms[i].cust.payment_advance) || rooms[i].cust.payment_advance < 0)
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
    for (i = 0; i < count; i++)
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

void admin::searchCustomer(char *pname)
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && strcmp(rooms[i].cust.name, pname) == 0)
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
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)
        {
            found = 1;
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
            for (int i = 0; i < count; i++)
            {
                if (rooms[i].roomNumber == rno)
                {
                    pro = 1;//checks if the room with that room number already exists
                    break;
                }
            }
            if (pro == 1)
            {
                cout << "\nRoom Number is Present.\nPlease enter a unique Number";
            }
            else
            {
                rooms[count] = rooms[count].addRoom(rno);
                count++;
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
    char pname[100];
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
            if (count == 0)
            {
                cout << "\nRoom data is NOT Available.\n Please add the rooms first.";
            }
            else
            {
                man.checkIn();
            }
            break;

        case 3:
            if (count == 0)
            {
                cout << "\nRooms data is NOT available.\nPlease add the rooms first";
            }
            else
            {
                man.AvailRoom();
                break;
            }
        case 4:
            if (count == 0)
            {
                cout << "\nRooms data is NOT available.\nPlease add the rooms first";
            }
            else
            {
                cout << "Enter Customer Name: ";
                cin >> pname;
                man.searchCustomer(pname);
            }
            break;

        case 5:
            if (count == 0)
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
