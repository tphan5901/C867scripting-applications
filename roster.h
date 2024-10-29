#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

class Roster {
public:
    // Constructor and Destructor
    Roster();
    ~Roster();

    void add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    Student* getStudentAt(int index) const;

public:
    //arr pointers
    Student* classRosterArray[5];
    int lastIndex;
};

#endif 
