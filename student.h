//
// Created by Sarah Bareh on 3/21/23.
//
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;


//#ifndef C867_STUDENT_H
//#define C867_STUDENT_H



using namespace std;

class Student {
public:
    const static int DaysArraySize = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int numDays [DaysArraySize];
    DegreeProgram degreeProgram;


public:
    Student();  //parameterless constructor
    Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram); //Full constructor
    ~Student(); //destructor

    //accessors
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getNumDays ();
    DegreeProgram getDegreeProgram();

    //mutators
    void setID (string studentID);
    void setFirstname (string firstName);
    void setLastname (string lastName);
    void setEmail (string email);
    void setAge (int age);
    void setNumDays (int numDays []);
    void setDegreeProgram (DegreeProgram degreeProgram);

    //displays a header for the data
    static void printHeader();

    //displays 'this' student data
    void print();
};




//#endif //C867_STUDENT_H
