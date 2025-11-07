// Author: Chris Jimenez
// Date: 12/7/2024
// Purpose: You are tasked with writing a program for a school administration system. The system tracks students enrolled in two classes: a Math class and a Programming class. 
// Your goal is to implement features that allow the administrator to analyze student data using set operations.

#include "SAS.h"
#include <set>
#include <unordered_set>
// Helper function to print a vector
void SAS::printVector(const std::vector<std::string>& vec) {
    bool first = true;
    for (const auto& student : vec) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << student;
        first = false;
    }
    std::cout << std::endl;
}

// Constructor to initialize the sets exactly as specified
SAS::SAS() {
    // Matching the exact initialization from the requirements
    mathClass = { "Sam", "Bob", "Charlie", "Diana", "Ed", "Freddy", "George", "Hannah", "Ian", "Julia" };
    programmingClass = { "Karen", "Sam", "Maria", "Nathan", "Sue", "Paul", "Elle", "Sam", "Bob", "Charlie", "Cecilia" };
}

// Display contents of Math Class
void SAS::displayMathClassContents() {
    std::cout << "Students in the Math Class:" << std::endl;
    printVector(mathClass);
}

// Display contents of Programming Class
void SAS::displayProgrammingClassContents() {
    std::cout << "Students in the Programming Class:" << std::endl;
    printVector(programmingClass);
}

// Display unique students
void SAS::displayUniqueStudents() {
    // Use std::set to remove duplicates while preserving order
    std::unordered_set<std::string> uniqueStudents;
    std::vector<std::string> unionStudents;

    for (const auto& student : mathClass) {
        if (uniqueStudents.insert(student).second) {
            unionStudents.push_back(student);
        }
    }

    for (const auto& student : programmingClass) {
        if (uniqueStudents.insert(student).second) {
            unionStudents.push_back(student);
        }
    }

    std::cout << "Union of Math and Programming Classes:" << std::endl;
    printVector(unionStudents);
}

// Display common students
void SAS::displayCommonStudents() {
    std::unordered_set<std::string> mathSet(mathClass.begin(), mathClass.end());
    std::vector<std::string> commonStudents;

    for (const auto& student : programmingClass) {
        if (mathSet.count(student) > 0 &&
            std::find(commonStudents.begin(), commonStudents.end(), student) == commonStudents.end()) {
            commonStudents.push_back(student);
        }
    }

    std::cout << "Intersection of Math and Programming Classes:" << std::endl;
    printVector(commonStudents);
}

// Display students only in Math class
void SAS::displayMathStudents() {
    std::unordered_set<std::string> progSet(programmingClass.begin(), programmingClass.end());
    std::vector<std::string> mathOnlyStudents;

    for (const auto& student : mathClass) {
        if (progSet.count(student) == 0) {
            mathOnlyStudents.push_back(student);
        }
    }

    std::cout << "Difference (Math - Programming):" << std::endl;
    printVector(mathOnlyStudents);
}

// Display students only in Programming class
void SAS::displayProgrammingStudents() {
    std::unordered_set<std::string> mathSet(mathClass.begin(), mathClass.end());
    std::vector<std::string> progOnlyStudents;

    for (const auto& student : programmingClass) {
        if (mathSet.count(student) == 0 &&
            std::find(progOnlyStudents.begin(), progOnlyStudents.end(), student) == progOnlyStudents.end()) {
            progOnlyStudents.push_back(student);
        }
    }

    std::cout << "Difference (Programming - Math):" << std::endl;
    printVector(progOnlyStudents);
}

// Display total unique students
void SAS::displayTotalUniqueStudents() {
    std::unordered_set<std::string> uniqueStudents;

    for (const auto& student : mathClass) {
        uniqueStudents.insert(student);
    }
    for (const auto& student : programmingClass) {
        uniqueStudents.insert(student);
    }

    std::cout << "Total Unique Students: " << uniqueStudents.size() << std::endl;
}

// Display total common students
void SAS::displayTotalCommonStudents() {
    std::unordered_set<std::string> mathSet(mathClass.begin(), mathClass.end());
    std::unordered_set<std::string> commonStudents;

    for (const auto& student : programmingClass) {
        if (mathSet.count(student) > 0) {
            commonStudents.insert(student);
        }
    }

    std::cout << "Total Students in Both Classes: " << commonStudents.size() << std::endl;
}