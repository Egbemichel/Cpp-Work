#include <iostream>  //standard
#include <fstream>   //responsible for the .txt file
#include <stdlib.h>  //
#include <cstdlib>   //
#include <conio.h>   //
#include <chrono>    //used to make the delay in execution
#include <thread>    //used to make the delay in execution
#include <windows.h> // used to navigate the console using (x, y) coordinates and can also resize the console
#include <stdio.h>   //
#include <string.h>  //
#include <time.h>    //
#include <iomanip>   //
#include <ctype.h>   //

#define max 50

using namespace std;

struct Employee
{

    char name[20];
    int jobCode;
    char designation[20];
    int exp;
    int age;
    double salary;
    char anyLoan;

    double tax;
    double mealAllowance;
    double transportAllowance;
    double medicalAllowance;
    double loanBalance;
    double loanDebit;
    double grossPay;
    double workingHours;
};
Employee emp[max], tempemp[max];
int num = 0;
void menu();
void intro();
void login();
void insert();
void edit();
void editmenu();
void editname(int);
void editjobCode(int);
void editdes(int);
void editexp(int);
void editage(int);
void editsalary(int);
void list();
void deletes();
void search();
void saveRecords(Employee, int);
bool isFilePresent();
void displayPayslip();
void Coord(int, int);
void delay(int);
void loading();
void border(int, int, int, int);
void loginFrame(int, int, int, int);

void insert()
{

    int i = num, j;
    double sal, TAX, mealA, transportA, medicalA, loanBal, loanDeb, grossPay, h;
    char Loan;
    num += 1;

    cout << "Insert New Record\n";
    for (int j = 0; j < num; j++)
    {
        Employee employee;

        cout << "Name: ";
        cin.ignore();
        cin >> employee.name;

        cout << "Job code: ";
        cin >> employee.jobCode;

        cout << "Designation: ";
        cin >> employee.designation;

        cout << "Years of experience: ";
        cin >> employee.exp;

        cout << "Age: ";
        cin >> employee.age;

        cout << "Enter working hours: ";
        cin >> h;

        sal = h * 2660;
        employee.workingHours = h;
        do
        {
            cout << "Any loan(Y/N) ?: \b\b";
            Loan = getche();
            if (Loan == 'Y' || Loan == 'y' || Loan == 'N' || Loan == 'n')
            {
                break;
            }
        } while (1);
        if (Loan == 'Y' || Loan == 'y')
        {
            cout << "Enter Loan Balance: ";
            cin >> loanBal;
        }
        else
        {
            loanBal = 0;
        }

        cout << "Recorded Succesfully...!!!";

        TAX = 0.01 * sal;
        mealA = 2660;
        medicalA = 2660;
        transportA = 2660;
        loanDeb = sal * 0.06;

        if (loanDeb > loanBal)
        {
            loanBal = 0;
            loanDeb = loanBal;
        }

        employee.salary = sal;
        employee.tax = TAX;
        employee.mealAllowance = mealA;
        employee.medicalAllowance = medicalA;
        employee.transportAllowance = transportA;
        employee.anyLoan = Loan;
        employee.loanDebit = loanDeb;
        employee.loanBalance = loanBal - loanDeb;
        employee.grossPay = (sal + mealA + transportA + medicalA) - (TAX + loanDeb);
        emp[i] = employee;
        
    }
    //saveRecords(emp,num);
    menu();
     cout << "Employee Data has been saved to Payroll.txt";
}
void intro()
{
    cout << "PAYROLL MANAGEMENT SYSTEM\n\n";
    cout << "*************************\n";
    cout << "Press any key to continue...";
    getch();
}
void login()
{
    char userName[30], password[30], ch;
    int i = 0, xLenS, yLenS, xLenE, yLenE;
    Coord(20, 10);
    cout << "Enter Username : ";
    cin >> userName;

    Coord(20, 12);
    cout << "Enter Password : ";
    cin >> password;
    /* while (1)
     {
         ch = getch();
         if (ch == 13)//Enter key
             break;
         if (ch == 32 || ch || 9)//Space or Tab key
             continue;
         else
         {
             cout << "*";
             password[i] = ch;
             i++;
         }
     }
     password[i] = '\0';*/
    if (strcmp(userName, "admin") == 0 && strcmp(password, "password") == 0)
    {
        system("cls");
        loginFrame(xLenS = 18, yLenS = 8, xLenE = 55, yLenE = 15);
        Coord(27, 10);
        cout << "Login Success!!!";
        Coord(21, 12);
        cout << "Will be redirected in 3 Seconds...";
        Coord(56, 12);
        delay(3000);
        Coord(44, 12);
        cout << "\b \b1";
        Coord(56, 12);
        delay(1000);
    }
    else
    {
        system("cls");
        loginFrame(xLenS = 18, yLenS = 8, xLenE = 55, yLenE = 15);
        Coord(27, 10);
        cout << "Access Denied!!!\n";
        Coord(21, 12);
        cout << "Will be redirected in 3 Seconds...";
        Coord(56, 12);
        delay(1000);
        Coord(44, 12);
        cout << "\b \b2";
        Coord(56, 12);
        delay(1000);
        Coord(44, 12);
        cout << "\b \b1";
        Coord(56, 12);
        delay(1000);
        system("cls");
        loginFrame(xLenS = 18, yLenS = 8, xLenE = 55, yLenE = 15);
        login();
    }
}

void edit()
{
    char option;
    int code;
    system("cls");
    cout << "Edit a Record";
    cout << "Enter the job code to edit: ";
    cin >> code;
    editmenu();
    for (int i = 0; i < num - 1; i++)
    {
        if (emp[i].jobCode == code)
        {
            while ((option = cin.get()) != 'q')
            {
                switch (option)
                {
                case 'n':
                    editname(i);
                    break;
                case 'j':
                    editjobCode(i);
                    break;
                case 'd':
                    editdes(i);
                    break;
                case 'e':
                    editexp(i);
                    break;
                case 'a':
                    editage(i);
                    break;
                case 's':
                    editsalary(i);
                    break;
                }
                editmenu();
            }
        }
    }
}
void editmenu()
{
    system("cls");

    cout << "Edit An Entry\n";
    cout << "What do you want to edit\n";

    cout << "Press n ---> Name.\n";

    cout << "Press j ---> Job code.\n";

    cout << "Press d ---> Designation.\n";

    cout << "Press e ---> Experience.\n";

    cout << "Press a ---> Age.\n";

    cout << "Press s ---> Salary.\n";

    cout << "Press q ---> Quit.\n";
    cout << "Select your Option ---->>>";
}
void editname(int i)
{
    cout << "Enter New Name--->  ";
    cin >> emp[i].name;
}
void editjobCode(int i)
{
    cout << "Enter Job code--->  ";
    cin >> emp[i].jobCode;
}
void editdes(int i)
{
    cout << "Enter New Designation--->  ";
    cin >> emp[i].designation;
}
void editexp(int i)
{
    cout << "Enter New Years of experience--->  ";
    cin >> emp[i].exp;
}
void editage(int i)
{
    cout << "Enter New Age--->  ";
    cin >> emp[i].age;
}
void editsalary(int i)
{
    double sal, TAX, mealA, transportA, medicalA, loanBal = emp[i].loanBalance, loanDeb, grossPay;

    cout << "Enter New Salary--->  ";
    cin >> sal;
    TAX = 0.01 * sal;
    mealA = 2660;
    medicalA = 2660;
    transportA = 2660;
    loanDeb = sal * 0.06;

    if (loanDeb > loanBal)
    {
        loanBal = 0;
        loanDeb = loanBal;
    }

    emp[i].salary = sal;
    emp[i].tax = TAX;
    emp[i].mealAllowance = mealA;
    emp[i].medicalAllowance = medicalA;
    emp[i].transportAllowance = transportA;

    emp[i].loanDebit = loanDeb;
    emp[i].loanBalance = loanBal;
    emp[i].grossPay = (sal + mealA + transportA + medicalA) - (TAX + loanDeb);
}
void list()
{
    int i, row;
    Coord(20, 4);
    cout << "************  List of the Employees ************ ";
    Coord(6, 6);
    cout << "Name\tJob code\tDesignation\tYears(EXP)\tage\tSalary\n";
    Coord(6, 7);
    cout
        << "--------------------------------------------------------";

    for (i = 0; row = 8; i <= (num - 1) << i++, row++)
    {
        Coord(6, row);
        cout << emp[i].name;
        Coord(19, row);
        cout << emp[i].jobCode;
        Coord(26, row);
        cout << emp[i].designation;
        Coord(47, row);
        cout << emp[i].exp;
        Coord(58, row);
        cout << emp[i].age;
        Coord(66, row);
        cout << emp[i].grossPay;
    }
    getch();
}
void deletes()
{
    for (int i = 0; i < num; i++)
    {
        tempemp[i] = emp[i];
    }
    int code;
    int check = -1;

    cout << "Delete a Record";

    cout << "Enter a Job code to Delete";
    cin >> code;
    int i, j;
    for (i = 0; i < num; i++)
    {
        if (emp[i].jobCode == code)
        {
            check = i;
        }
    }
    if (check != -1)
    {
        for (i = 0, j = 0; i < num; i++, j++)
        {
            if (i == check)
            {
                i++;
            }
            emp[j] = tempemp[i];
        }
        num--;
    }
}
void search()
{
    int code;
    bool found = false;
    cout << "You can search only through Job Codes";
    cout << "Enter Job Code";
    cin >> code;

    for (int i = 0; i <= num - 1; i++)
    {
        if (emp[i].jobCode == code)
        {
            Coord(6, 8);
            cout << "Name\tJob code\tDesignation\tYears(EXP)\tage\tSalary\n";
            cout << "------------------------------------------------------------\n\n";
            Coord(6, 11);
            cout << emp[i].name;
            Coord(19, 11);
            cout << emp[i].jobCode;
            Coord(26, 11);
            cout << emp[i].designation;
            Coord(47, 11);
            cout << emp[i].exp;
            Coord(58, 11);
            cout << emp[i].age;
            Coord(66, 11);
            cout << emp[i].grossPay;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No Records Found...!!!";
    }
    getch();
}

bool isFilePresent()
{
    ifstream inputFile("Payroll.txt");
    return inputFile.good();
}
void displayPayslip()
{
    system("cls");
    Coord(10, 4);
    int code, i;
    cout << "Enter Employee Job Code: ";
    cin >> code;
    for (i = 0; i <= num - 1; i++)
    {
        if (emp[i].jobCode == code)
        {
            Coord(12, 6);
            cout << "Name : " << emp[i].name;

            Coord(45, 6);
            cout << "Working Hours : " << emp[i].workingHours << " Hrs";

            Coord(6, 8);
            cout << "Earnings :-";

            Coord(8, 12);
            cout << "Basic Pay : " << emp[i].salary << endl;

            Coord(8, 14);
            cout << "Meal Allowance : " << emp[i].mealAllowance << endl;

            Coord(8, 16);
            cout << "Medical Allowance : " << emp[i].medicalAllowance << endl;

            Coord(8, 18);
            cout << "Transport Allowance : " << emp[i].transportAllowance << endl;

            Coord(8, 20);
            cout << "Deductions :-" << endl
                 << endl;

            Coord(40, 8);
            cout << "Tax : " << emp[i].tax << endl;

            Coord(42, 10);
            int l = emp[i].anyLoan;
            char l2 = toupper(l);
            cout << "Loan Status :" << l2 << endl;

            Coord(42, 12);
            cout << "Loan Debit This Month : " << emp[i].loanDebit << endl;

            Coord(42, 14);
            cout << "Loan Balance : " << emp[i].loanBalance << endl;

            Coord(32, 22);
            cout << "Total Gross Pay : " << emp[i].grossPay;
        }
    }
    getch();
}
void Coord(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void delay(int msec)
{
    this_thread::sleep_for(chrono::milliseconds(msec));
}
void border(int xLenS = 3, int yLenS = 3, int xLenE = 77, int yLenE = 23)
{
    system("cls");
    Coord(xLenS, yLenS);
    cout << char(201);
    Coord(xLenS, yLenE);
    cout << char(200);

    for (int i = xLenS + 1; i <= xLenE - 1; i++)
    {
        delay(15);
        Coord(i, yLenS);
        cout << char(205);
        Coord(i, yLenE);
        cout << char(205);
    }
    Coord(xLenE, yLenS);
    cout << char(187);
    Coord(xLenE, yLenE);
    cout << char(188);
    for (int i = yLenS + 1; i <= yLenE - 1; i++)
    {
        delay(15);
        Coord(xLenS, i);
        cout << char(186);
        Coord(xLenE, i);
        cout << char(186);
    }
    cout << "\n\n";
}
void loginFrame(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
    border(xLenS, yLenS, xLenE, yLenE);
}


void getRecords(Employee emp[], int &num)
{
    cout << "Payroll Management System";
    ifstream inputFile;
    inputFile.open("Payroll.txt", ios::in);
    if (!inputFile.is_open())
    {
        cerr << "Unable to open file: Payroll.txt" << endl;
        return;
    }
    int c = 0;
    Employee data;

    inputFile.read(reinterpret_cast<char *>(&data), sizeof(data));
    while (!inputFile.eof())
    {
        cout << "Name: " << data.name << endl;
        cout << "jobCode: " << data.jobCode << endl;
        cout << "Designation: " << data.designation << endl;
        cout << "Years of experience: " << data.exp << endl;
        cout << "Age: " << data.age << endl;
        cout << "Salary: " << data.salary << endl;
        cout << "Any loan: " << data.anyLoan << endl;
        cout << "Tax: " << data.tax << endl;
        cout << "Meal Allowance: " << data.mealAllowance << endl;
        cout << "Transport Allowance: " << data.transportAllowance << endl;
        cout << "Medical Allowance: " << data.medicalAllowance << endl;
        cout << "Loan Balance: " << data.loanBalance << endl;
        cout << "Gross Pay: " << data.grossPay << endl;
        cout << "Working Hours: " << data.workingHours << endl;
        
        inputFile.read(reinterpret_cast<char *>(&data), sizeof(data));
        c++;
    }
    // while (c < max && inputFile >> emp[c].name >> emp[c].jobCode >> "\t" >> emp[c].designation >> "\t" >> emp[c].exp >> "\t" >> emp[c].age >> "\t" >> emp[c].salary >> "\t" >> emp[c].anyLoan >> "\t" >> emp[c].tax >> "\t" >> emp[c].mealAllowance >> "\t" >> emp[c].transportAllowance >> "\t" >> emp[c].medicalAllowance >> "\t" >> emp[c].loanBalance >> "\t" >> emp[c].grossPay >> "\t" >> emp[c].workingHours >> "\t")
    //{

    //  c++;
    // }
    num = c;
    inputFile.close();
    cout << "The program is complete";
}
void saveRecords(Employee emp[], int num)
{
    if (num == 0)
    {
        system("del Payroll.txt");
    }

    ofstream outputFile("Payroll.txt");

    if (!outputFile.is_open())
    {
        cerr << "Unable to open file: Payroll.txt" << endl;
        return;
    }

    for (int i = 0; i < num; i++)
    {
        outputFile << emp[i].name << "\t" << emp[i].jobCode << "\t" << emp[i].designation << "\t" << emp[i].exp << "\t" << emp[i].age << "\t" << emp[i].salary << "\t" << emp[i].anyLoan << "\t" << emp[i].tax << "\t" << emp[i].mealAllowance << "\t" << emp[i].transportAllowance << "\t" << emp[i].medicalAllowance << "\t" << emp[i].loanBalance << "\t" << emp[i].loanDebit << "\t"
                   << "\t" << emp[i].grossPay << "\t" << emp[i].workingHours << "\t";
    }
    outputFile.close();
}
void loading()
{
    system("cls");
    cout << "Loading...";
    for (int i = 0; i < 3; ++i)
    {
        delay(500);
        cout << char(250);
    }
}

void menu()
{
    char option;
    system("cls");
    Coord(16, 4);
    cout << "****PAYROLL MANAGEMENT SYSTEM****\n\n";
    Coord(12, 6);
    cout << "Press i ---> Insert new record.\n";
    Coord(12, 8);
    cout << "Press e ---> Edit a record.\n";
    Coord(12, 10);
    cout << "Press d ---> Delete a record.\n";
    Coord(12, 12);
    cout << "Press s ---> Search a record.\n";
    Coord(12, 14);
    cout << "Press l ---> List the employee table.\n";
    Coord(12, 16);
    cout << "Press p ---> Print the employee payslip.\n";
    Coord(12, 18);
    cout << "Press q ---> Quit program.\n";
    Coord(12, 20);
    cout << "Select your Option ====> \n";
    cin >> option;

    if (emp[0].jobCode == 0 && isFilePresent())
        num--;
    while (1)
    {
        option = getch();
        switch (option)
        {
        case 'i':
            insert();
            break;
        case 'e':
            edit();
            break;
        case 'd':
            deletes();
            break;
        case 's':
            search();
            break;
        case 'l':
            list();
            break;
        case 'p':
            displayPayslip();
            break;
        case 'q':
            saveRecords(emp, num);
            exit(0);
        }
    }
}
int main()
{
    border();
    intro();
    loading();
    loginFrame();
    login();
    menu();
    insert();
    getRecords(emp, num);
    // menu();
    // if (emp[0].jobCode == 0 && isFilePresent())
    //  num--;
    // while (1)
    // {
    // option = getch();
    /* switch (option)
     {
     case 'i':
         insert();
         break;
     case 'e':
         edit();
         break;
     case 'd':
         deletes();
         break;
     case 's':
         search();
         break;
     case 'l':
         list();
         break;
     case 'p':
         displayPayslip();
         break;
     case 'q':
         saveRecords();
         exit(0);
     }*/
   
    // }
    return 0;
}