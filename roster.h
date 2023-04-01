//
// Created by Sarah Bareh on 3/21/23.
//
#pragma once
#include "student.h"
//#include <iostream>
//#include <string>
//#include "degree.h"


//#ifndef C867_ROSTER_H
//#define C867_ROSTER_H

class Roster
{
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray [numStudents];

    /*a.  public void add(string studentID, string firstName, string lastName, string email,
    int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram)
     that sets the instance variables from part D1 and updates the roster.*/
public:
    void parse (string row);
    void add (string studentID,
              string firstName,
              string lastName,
              string email,
              int age,
              int numDays1,
              int numDays2,
              int numDays3,
              DegreeProgram degreeProgram);


    //b.  public void remove(string studentID)
    void removeStudentByID(string studentID);

    //c. public void printAll()
    void printAll();

    //d.  public void printAverageDaysInCourse(string studentID)
    void printAverageDaysInCourse(string studentID);

    //e.  public void printInvalidEmails()
    void printInvalidEmails();

    //f.  public void printByDegreeProgram(DegreeProgram degreeProgram)
    void printByDegreeProgram(DegreeProgram degreeProgram);

    ~Roster();
};

//#endif //C867_ROSTER_H

