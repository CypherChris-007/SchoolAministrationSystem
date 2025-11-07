// Author: Chris Jimenez
// Date: 12/7/2024
// Purpose: You are tasked with writing a program for a school administration system. The system tracks students enrolled in two classes: a Math class and a Programming class. 
// Your goal is to implement features that allow the administrator to analyze student data using set operations.
#ifndef SAS_H
#define SAS_H

#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class SAS
{
private:
    // Define sets using exact initial configuration
    vector<std::string> mathClass;
    vector<std::string> programmingClass;

    // Helper function to print a vector
    void printVector(const std::vector<std::string>& vec);

public:
    // Constructor to initialize the sets
    SAS();//School Admiration System

    // Display Contents of Each Set
    void displayMathClassContents();
    void displayProgrammingClassContents();

    // Set Operations
    void displayUniqueStudents();//Display all unique students across both classes
    void displayCommonStudents();//Display the names of students enrolled in both classes
    void displayMathStudents();//Math only students
    void displayProgrammingStudents();//Programming only students
    void displayTotalUniqueStudents();//Total # of unique
    void displayTotalCommonStudents();//Total # of common students

};

#endif // SAS_H
