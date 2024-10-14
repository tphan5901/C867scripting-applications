#include <iostream>
#include <sstream>
#include "roster.h"

// Constructor: initializes lastIndex to -1 indicating an empty roster
Roster::Roster() : lastIndex(-1) {}

// Destructor. deallocate mem for student object
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
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            break;
        }
    }
}

void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

//classrosterarr.getdaysinCourse() but with ->
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            std::cout << "Average days in course for student ID " << studentID << ": "
                      << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
        
    }
    std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; i++) {
        //student.h accessor
        std::string email = classRosterArray[i]->getEmail();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
// const degree
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// Accessor for classRosterArray
Student* Roster::getStudentAt(int index) const {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index];
    }
    return nullptr;
}
