#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>
#include <algorithm>

using namespace std;
/*Prevent hardcoding
Add Utility functions*/

const int maxCourses = 6;

struct Student
{
    string name;
    string matricule;
    int numCourses;
    string courses[maxCourses];
};

// Function to input student details
Student inputStudentDetails()
{
    Student newStudent;
    cout << "Enter Matricule: ";
    getline(cin, newStudent.matricule);

    cout << "Enter Name: ";
    getline(cin, newStudent.name);

    do
    {
        cout << "Enter Number of courses (up to " << maxCourses << "): ";
        cin >> newStudent.numCourses;

        if (cin.fail() || newStudent.numCourses < 0 || newStudent.numCourses > maxCourses)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number of courses between 0 and " << maxCourses << ".\n";
        }

    } while (cin.fail() || newStudent.numCourses < 0 || newStudent.numCourses > maxCourses);

    cin.ignore(); // Clear the newline character left in the buffer

    cout << "Enter your courses:\n";
    for (int i = 0; i < newStudent.numCourses; i++)
    {
        cout << "Course " << i + 1 << ": ";
        getline(cin, newStudent.courses[i]);
    }

    return newStudent;
}

// Function to write student details to a text file
void writeStudentToFile(const Student &student)
{
    ofstream outputFile("students.txt", ios::app);
    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    outputFile << student.matricule << " " << student.name << " " << student.numCourses;

    for (int i = 0; i < student.numCourses; i++)
    {
        outputFile << " " << student.courses[i];
    }

    outputFile << "\n";
    outputFile.close();

    cout << "Student details saved to students.txt." << endl;
}

// Function to display all students from the file
/*void displayStudentDetails(const Student &stud)
{



}*/

// Function to edit records
/*void editStudentDetails(const Student &stud)
{



}*/


// Function to delete records
/*void deleteStudentDetails(const Student &stud)
{



}*/

int main()
{
    vector<Student> students;
    char choice;

    do
    {
        cout << "\nStudent Management System:\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cin.ignore(); // Clear the input buffer
            writeStudentToFile(inputStudentDetails());
            break;

        case '3':
            cout << "Exiting the Student Management System." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '3');

    return 0;
}
