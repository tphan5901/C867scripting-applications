#include <iostream>
#include "student.h"

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), email(email), age(age), degreeProgram(degreeProgram) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmail() const { return email; }
int Student::getAge() const { return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }
 
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmail(std::string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// print statement
void Student::print() const {
    std::cout << "Student ID: " << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";
    std::cout << "Degree Program: ";
    switch (degreeProgram) {
        case SECURITY: std::cout << "SECURITY"; break;
        case NETWORK: std::cout << "NETWORK"; break;
        case SOFTWARE: std::cout << "SOFTWARE"; break;
    }
    std::cout << std::endl;
}
