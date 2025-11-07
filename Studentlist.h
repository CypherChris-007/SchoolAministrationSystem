// SchoolAdministrationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Chris Jimenez
// Date: 12/7/2024
// Purpose: Menu functions
// StudentList.h
#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <string>

class StudentNode {
public:
    std::string name;
    StudentNode* next;

    StudentNode(const std::string& studentName);
};

class Studentlist
{
private:
    StudentNode* head;

public:
    // Constructor
    Studentlist();

    // Destructor
    ~Studentlist();

    // Add a student to the end of the list
    void addStudent(const std::string& name);

    // Display all students in the list
    void displayStudents();

    // Search for a student in the list
    bool searchStudent(const std::string& name);

    // Delete a student from the list
    void deleteStudent(const std::string& name);

    // Count the number of students in the list
    int countStudents();
};

#endif // STUDENT_LIST_H

