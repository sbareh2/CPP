//
// Created by Sarah Bareh on 3/21/23.
//

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string>
#include <regex>

#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;


/* E.  Create a Roster class (roster.cpp) by doing the following:
1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
 (Constructors included) */

void Roster::parse(string studentData) {
//    DegreeProgram dp = UNKNOWN;
//    if (studentData.at(8) == 'S') {
//        dp = DegreeProgram::SECURITY;
//    } else if (studentData.at(8) == 'N') {
//        dp = DegreeProgram::NETWORK;
//    } else if (studentData.at(8) == 'E') {
//        dp = DegreeProgram::SOFTWARE;
//    }


    int rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstname = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastname = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stod(studentData.substr(lhs, rhs - lhs));


    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int numDays1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int numDays2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int numDays3 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string strDegreeProgram = studentData.substr(lhs, rhs - lhs);

    DegreeProgram degreeProgram = UNKNOWN;
    if (strDegreeProgram == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (strDegreeProgram == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (strDegreeProgram == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    };

    add(studentID, firstname, lastname, email, age, numDays1, numDays2, numDays3, degreeProgram);
}

//    a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age
// , int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
// that sets the instance variables from part D1 and updates the roster.

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int numDays1,
                     int numDays2, int numDays3, DegreeProgram degreeProgram)
{
        int numDaysarr[3] = {numDays1, numDays2, numDays3};
        classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, numDaysarr, degreeProgram);
 }



//    b.  public void remove(string studentID)  that removes students from the roster by student ID.
//    If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::removeStudentByID(string studentID)
{
    bool removed = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i] -> getID() == studentID)
        {
            removed = true;
            if (i < numStudents -1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents-1];
                classRosterArray[numStudents-1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (removed)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
       
    }
    else cout << studentID << " not found." << std::endl << std::endl;
}


//    c. public void printAll() that prints a complete tab-separated list of student data
//    in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20
//    [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the
//    students in classRosterArray and call the print() function for each student.
void Roster::printAll()
 {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
//        cout << classRosterArray[i] ->getID(); cout << '\t';
//        cout << classRosterArray[i] ->getFirstName(); cout << '\t';
//        cout << classRosterArray[i] ->getLastName(); cout << '\t';
//        cout << classRosterArray[i] ->getEmail(); cout << '\t';
//        cout << classRosterArray[i] ->getAge(); cout << '\t' << '{';
//        cout << classRosterArray[i] ->getNumDays()[0]; cout << ',';
//        cout << classRosterArray[i] ->getNumDays()[1]; cout << ',';
//        cout << classRosterArray[i] ->getNumDays()[2]; cout << '}' << '\t';
//        cout << DegreeProgramString[classRosterArray[i] ->getDegreeProgram()] << std::endl;
    classRosterArray[i] ->Student::print();
    }

 }

//d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days
// in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i] ->getID() << ": ";
        cout << (classRosterArray[i] -> getNumDays()[0]
                + classRosterArray[i] -> getNumDays()[1]
                + classRosterArray[i] -> getNumDays()[2]) / 3.0 << std::endl;
    }
    cout << std::endl;
}


//e.    A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails()
{
//    bool any = false;
    for (int i = 0; i < numStudents; i++)
    {
        string email = (classRosterArray[i] ->getEmail());
        if ( (classRosterArray[i]->getEmail().find('@') == -1) )
        {
            cout << classRosterArray[i]->getEmail() << endl;
        }
        else if ( (classRosterArray[i]->getEmail()).find('.') == -1)
        {
            cout << classRosterArray[i]->getEmail() << endl;
        }
        else if ( (classRosterArray[i]->getEmail()).find(' ') != -1)
        {
            cout << classRosterArray[i]->getEmail() << endl;
        }
    }
//        if (!any) cout << "NONE" << std::endl;
 }

//f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information
// for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]-> getDegreeProgram() == degreeProgram) classRosterArray[i] -> print();
    }
    cout << std::endl;
}



Roster::~Roster()
{
    cout << "DESTRUCTOR CALLED" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Removing Student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

