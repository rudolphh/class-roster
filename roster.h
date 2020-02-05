#pragma once
#include <vector>
#include "student.h"

using std::vector;

class Roster {

    Student** classRosterArray;// Requirements E.1.
    int max;

    public:
    
    Roster(int numStudents);
    ~Roster();

    void add(string studentID, string firstName, string lastName, string email, int age, 
                int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program);
        
    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(int degreeProgram);

    void getStudentIDs(vector<string>& studentIDs);

};