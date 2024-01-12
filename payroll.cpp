#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Employee structure to store employee information
struct Employee
{
    string name;
    int employeeId;
    double hourlyRate;
    double hoursWorked;
    double grossPay;
};

// Function to calculate gross pay for an employee
void calculateGrossPay(Employee &emp)
{
    emp.grossPay = emp.hourlyRate * emp.hoursWorked;
}

// Function to display employee details
void displayEmployeeDetails(const Employee &emp)
{
    cout << "Employee ID: " << emp.employeeId << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Hourly Rate: $" << emp.hourlyRate << endl;
    cout << "Hours Worked: " << emp.hoursWorked << " hours" << endl;
    cout << "Gross Pay: $" << emp.grossPay << endl;
}

// Function to save employee records to a file
void saveRecords(const vector<Employee> &employees)
{
    ofstream outputFile("payroll.txt", ios::trunc); // Open file for writing (truncating existing content)
    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const Employee &emp : employees)
    {
        outputFile << emp.employeeId << " " << emp.name << " " << emp.hourlyRate
                   << " " << emp.hoursWorked << " " << emp.grossPay << endl;
    }

    outputFile.close();
    cout << "Employee records saved to payroll.txt." << endl;
}

// Function to load employee records from a file
void loadRecords(vector<Employee> &employees)
{
    ifstream inputFile("payroll.txt"); // Open file for reading
    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    Employee emp;
    while (inputFile >> emp.employeeId >> emp.name >> emp.hourlyRate >> emp.hoursWorked >> emp.grossPay)
    {
        employees.push_back(emp);
    }

    inputFile.close();
    cout << "Employee records loaded from payroll.txt." << endl;
}

int main()
{
    vector<Employee> employees;

    // Load existing records from file
    loadRecords(employees);

    // Menu loop
    char choice;
    do
    {
        cout << "\nPayroll System Menu:\n";
        cout << "1. Add New Employee\n";
        cout << "2. Display Employee Details\n";
        cout << "3. Calculate Gross Pay\n";
        cout << "4. Save Records to File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1': // Add New Employee
        {
            Employee newEmployee;
            cout << "Enter Employee ID: ";
            cin >> newEmployee.employeeId;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, newEmployee.name);
            cout << "Enter Hourly Rate: $";
            cin >> newEmployee.hourlyRate;
            cout << "Enter Hours Worked: ";
            cin >> newEmployee.hoursWorked;

            // Calculate Gross Pay
            calculateGrossPay(newEmployee);

            // Add new employee to the vector
            employees.push_back(newEmployee);

            cout << "Employee added successfully." << endl;
        }
        break;

        case '2': // Display Employee Details
        {
            int empId;
            cout << "Enter Employee ID: ";
            cin >> empId;

            // Find the employee with the given ID
            auto it = find_if(employees.begin(), employees.end(),
                              [empId](const Employee &emp)
                              { return emp.employeeId == empId; });

            if (it != employees.end())
            {
                displayEmployeeDetails(*it);
            }
            else
            {
                cout << "Employee not found." << endl;
            }
        }
        break;

        case '3': // Calculate Gross Pay
        {
            int empId;
            cout << "Enter Employee ID: ";
            cin >> empId;

            // Find the employee with the given ID
            auto it = find_if(employees.begin(), employees.end(),
                              [empId](const Employee &emp)
                              { return emp.employeeId == empId; });

            if (it != employees.end())
            {
                calculateGrossPay(*it);
                cout << "Gross Pay calculated successfully." << endl;
            }
            else
            {
                cout << "Employee not found." << endl;
            }
        }
        break;

        case '4': // Save Records to File
            saveRecords(employees);
            break;

        case '5': // Exit
            cout << "Exiting the Payroll System." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
