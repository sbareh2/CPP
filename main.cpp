#include <iostream>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include <string>
#include "degree.h"


using namespace std;

string studentID;
const int numStudents = 5;
const string studentData[] ={
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Sarah,Bareh,sbareh@wgu.edu,32,22,30,14,SOFTWARE"
    
};

int main() {
    // 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

        cout << "Scripting and Programming Applications - C867" << endl;
        cout << "Language: C++" << endl;
        cout << "WGU Student ID: 010442044" << endl;
        cout << "Student Name: Sarah Bareh" << endl << endl;

    //2.  Create an instance of the Roster class called classRoster.
    Roster classRoster;

    //3.  add students to roster
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << endl;
    
    //4. printAll
    classRoster.printAll();
    cout << std::endl;

    //4. print invalid emails
    cout << "Displaying invalid emails: " << std:: endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    //4. print average days in course by student ID
    cout << "Displaying average days in course: " << std::endl;
    classRoster.printAverageDaysInCourse(studentID);

    //4. Displaying by degree program
    for (int i = 0; i < 4; i++)
    {
        cout << "Displaying by Degree Program: " << DegreeProgramString[i] << std::endl;
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }


    //4. removing student by ID
    cout << "Removing student with ID A4" << std::endl;
    classRoster.removeStudentByID("A4");
    cout << std::endl;
    
    classRoster.printAll();
    cout << std::endl;
    

    cout << "Removing student with ID A4" << std::endl;
    classRoster.removeStudentByID("A4");
    cout << std::endl;

    //::system("pause");
    return 0;
}
