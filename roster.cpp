#include <iostream>
#include <sstream>
#include "roster.h"

// Constructor
Roster::Roster() : lastIndex(-1) {}

// Deallocate memory for student objects
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
}

//add method
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    Student* student = new Student(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    classRosterArray[++lastIndex] = student;
}

//remove method
void Roster::remove(std::string studentID) {
    bool studentFound = false; 
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            studentFound = true;
            std::cout << "Student with ID " << studentID << " was removed from roster." << std::endl;
            break;
        } //else {
         //   std::cout << "Student with ID" << studentID << "was removed from roster" << std::endl;
      //  }
    }
    
    if (!studentFound) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

//average days
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            std::cout << "Average days in course for student ID " << studentID << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
        
    }
    std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
}

//validate email
void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; i++) {
        std::string email = classRosterArray[i]->getEmail();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << email << " is invalid." << std::endl;
        } 
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

Student* Roster::getStudentAt(int index) const {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index];
    }
    return nullptr;
}
