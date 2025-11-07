// SchoolAdministrationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Chris Jimenez
// Date: 12/7/2024
// Purpose: You are tasked with writing a program for a school administration system. The system tracks students enrolled in two classes: a Math class and a Programming class. 
// Your goal is to implement features that allow the administrator to analyze student data using set operations.
#include "SAS.h"
#include "Studentlist.h"
#include <iostream>
#include <string>
using namespace std;
// Function to display menu options
void displayMenu() {
    cout << "\n--- Student List Management System ---" << std::endl;
    cout << "1. Add a Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search for a Student" << endl;
    cout << "4. Delete a Student" << endl;
    cout << "5. Count Students" << endl;
    cout << "6. Exit Program" << endl;
    cout << "Enter your choice (1-6): ";
}
int main()
{
 //Studentlist instantiate
    SAS admin;       // Object to manage the set operations
    Studentlist studentList; // Object to manage the linked list of students//Varables
    int choice;
    string name;
    //display part 1

        // Display Contents of Each Set
    admin.displayMathClassContents();
    admin.displayProgrammingClassContents();

    // Set Operations
    admin.displayUniqueStudents();//Display all unique students across both classes
    admin.displayCommonStudents();//Display the names of students enrolled in both classes
    admin.displayMathStudents();//Math only students
    admin.displayProgrammingStudents();//Programming only students
    admin.displayTotalUniqueStudents();//Total # of unique
    admin.displayTotalCommonStudents();//Total # of common students
    cout << "========================" << endl;
    //Part 2
    do {
        // Display menu and get user choice
        displayMenu();

        // Check if input is valid
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        // Process user choice
        switch (choice) {
        case 1: {
            cout << "Enter student name to add: ";
            cin.ignore(); // Clear newline from previous input
            getline(cin, name);
            studentList.addStudent(name);
            break;
        }
        case 2: {
            studentList.displayStudents();
            break;
        }
        case 3: {
            cout << "Enter student name to search: ";
            cin.ignore(); // Clear newline from previous input
            getline(cin, name);
            studentList.searchStudent(name);
            break;
        }
        case 4: {
            cout << "Enter student name to delete: ";
            cin.ignore(); // Clear newline from previous input
            getline(cin, name);
            studentList.deleteStudent(name);
            break;
        }
        case 5: {
            cout << "Total number of students: " << studentList.countStudents() << endl;
            break;
        }
        {
        case 6:
            cout << "Exiting program...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;

    }
