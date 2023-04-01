//
// Created by Sarah Bareh on 3/21/23.
//
//#include <iostream>
//#include <string>
#include "student.h"
//using std::cout;

Student::Student()  //parameterless constructor
{
    this ->studentID = "";
    this ->firstName = "";
    this ->lastName = "";
    this ->email = "";
    this ->age = 0;
    for (int  i = 0; i < DaysArraySize; i++) this->numDays[i] = 0;
    this ->degreeProgram = DegreeProgram::UNKNOWN;
}

//full constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram)
{
    this -> studentID = studentID;
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> email = email;
    this -> age = age;
    for (int  i = 0; i < DaysArraySize; i++) this -> numDays[i] = numDays[i];
    this -> degreeProgram = degreeProgram;
}

Student::~Student() {}; //destructor


// Accessors
string Student::getID() { return this->studentID; }
string Student::getFirstName(){ return this->firstName; }
string Student::getLastName(){ return this->lastName; }
string Student::getEmail(){ return this->email; }
int Student::getAge(){ return this->age; }
int* Student::getNumDays(){ return this->numDays; }
DegreeProgram Student::getDegreeProgram(){ return this->degreeProgram; }


// Mutators
void Student::setID (string studentID) { this -> studentID = studentID; }
void Student::setFirstname (string firstName){ this -> firstName = firstName; }
void Student::setLastname (string lastName){ this -> lastName = lastName; }
void Student::setEmail (string email){ this -> email = email; }
void Student::setAge (int age){ this -> age = age; }
void Student::setNumDays (int numDays [])
{
    for (int i = 0; i < DaysArraySize; i++) this-> numDays[i] = numDays[i];
}
void Student::setDegreeProgram (DegreeProgram degreeProgram){ this ->degreeProgram = degreeProgram; }

//print the header
void Student::printHeader()
{
    cout << "ID|First Name|Last Name|Email|Age|Number of Days|Degree Program\n";
}


void Student::print()
{
    cout << this-> getID() << '\t';
    cout << this-> getFirstName() << '\t';
    cout << this-> getLastName() << '\t';
    cout << this-> getEmail() << '\t';
    cout << this-> getAge() << '\t' << '{';
    cout << this-> getNumDays()[0] << ',';
    cout << this-> getNumDays()[1] << ',';
    cout << this-> getNumDays()[2] << '}' << '\t';
    cout << DegreeProgramString [this-> getDegreeProgram()] << '\n';
}
