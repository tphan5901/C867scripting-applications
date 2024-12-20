#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

int main() {
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Thinh,Phan,tphan5901@gmail.com,22,33,22,13,SOFTWARE"
    };

    Roster classRoster;

   for (int i = 0; i < 5; i++) {
        stringstream ss(studentData[i]);
        string studentID, firstName, lastName, email, ageStr, daysInCourse1Str, daysInCourse2Str, daysInCourse3Str, degreeProgramStr;
        getline(ss, studentID, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, email, ',');
        getline(ss, ageStr, ',');
        getline(ss, daysInCourse1Str, ',');
        getline(ss, daysInCourse2Str, ',');
        getline(ss, daysInCourse3Str, ',');
        getline(ss, degreeProgramStr, ',');

        cout << "Parsing data: " << studentData[i] << endl;
        try {
            int age = stoi(ageStr);
            int daysInCourse1 = stoi(daysInCourse1Str);
            int daysInCourse2 = stoi(daysInCourse2Str);
            int daysInCourse3 = stoi(daysInCourse3Str);
            DegreeProgram degreeProgram;

            if (degreeProgramStr == "SECURITY") degreeProgram = SECURITY;
            else if (degreeProgramStr == "NETWORK") degreeProgram = NETWORK;
            else if (degreeProgramStr == "SOFTWARE") degreeProgram = SOFTWARE;
            else throw invalid_argument("Not a Degree program");

            classRoster.add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
        } catch (const invalid_argument& e) {
            cerr << "Error parsing student data: " << studentData[i] << endl;
            cerr << e.what() << endl;
        }
    }

    cout << "\n"; 
    cout << "Course: C867 Script/Appl" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 011746951" << endl;
    cout << "Name: Thinh Phan" << endl << endl;

    cout << "Class Roster: " << std::endl;
    classRoster.printAll();

	cout << "\n";
    cout << "Invalid Emails: ";
	classRoster.printInvalidEmails();
	cout << std::endl;

    cout << "Average days in course: " << std::endl;
    for (int i = 0; i < 5; i++) {
        if (classRoster.getStudentAt(i) != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.getStudentAt(i)->getStudentID());
        }
    }
    cout << "\n";
    cout << "Displaying degree programs:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    classRoster.remove("A3");
    classRoster.remove("A3");

    return 0;
}
