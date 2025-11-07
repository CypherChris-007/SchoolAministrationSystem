// SchoolAdministrationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Chris Jimenez
// Date: 12/7/2024
// Purpose: define the menu functions
// StudentList.cpp
#include "Studentlist.h"
#include <iostream>

// StudentNode Constructor
StudentNode::StudentNode(const std::string& studentName)
    : name(studentName), next(nullptr) {
}

// StudentList Constructor
Studentlist::Studentlist() : head(nullptr) {}

// Destructor to free memory
Studentlist::~Studentlist() {
    while (head != nullptr) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add a student to the end of the list
void Studentlist::addStudent(const std::string& name) {
    StudentNode* newNode = new StudentNode(name);

    if (head == nullptr) {
        // If list is empty, new node becomes the head
        head = newNode;
        std::cout << "Student '" << name << "' added successfully." << std::endl;
        return;
    }

    // Traverse to the end of the list
    StudentNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    std::cout << "Student '" << name << "' added successfully." << std::endl;
}

// Display all students in the list
void Studentlist::displayStudents() {
    if (head == nullptr) {
        std::cout << "No students in the list." << std::endl;
        return;
    }

    std::cout << "Students in the list:" << std::endl;
    StudentNode* current = head;
    int count = 1;
    while (current != nullptr) {
        std::cout << count << ". " << current->name << std::endl;
        current = current->next;
        count++;
    }
}

// Search for a student in the list
bool Studentlist::searchStudent(const std::string& name) {
    StudentNode* current = head;
    int position = 1;

    while (current != nullptr) {
        if (current->name == name) {
            std::cout << "Student '" << name << "' found at position " << position << "." << std::endl;
            return true;
        }
        current = current->next;
        position++;
    }

    std::cout << "Student '" << name << "' not found in the list." << std::endl;
    return false;
}

// Delete a student from the list
void Studentlist::deleteStudent(const std::string& name) {
    // If list is empty
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete." << std::endl;
        return;
    }

    // If head node needs to be deleted
    if (head->name == name) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
        std::cout << "Student '" << name << "' deleted successfully." << std::endl;
        return;
    }

    // Search and delete from the rest of the list
    StudentNode* current = head;
    while (current->next != nullptr) {
        if (current->next->name == name) {
            StudentNode* temp = current->next;
            current->next = temp->next;
            delete temp;
            std::cout << "Student '" << name << "' deleted successfully." << std::endl;
            return;
        }
        current = current->next;
    }

    // If student not found
    std::cout << "Student '" << name << "' not found in the list." << std::endl;
}

// Count the number of students in the list
int Studentlist::countStudents() {
    int count = 0;
    StudentNode* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}
