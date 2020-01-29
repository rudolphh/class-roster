#pragma once

#include "student.h"

const string studentData[] = { 
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Rudy,Hernandez,rhern87@wgu.edu,37,40,7,15,SOFTWARE" 
};

class Roster {

    Student** classRosterArray;// Requirements E.1.

    public:
    
    Roster();
    ~Roster();

    void add(string ID, string firstName, string lastName, string email, int age, 
                int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program);
        
    void remove(string studentID);

    void printAll();

    void printDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(int degreeProgram);

};