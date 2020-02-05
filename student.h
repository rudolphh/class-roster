#pragma once
#include <string>
#include "degree.h"
using std::string;

// Requirements D.1.
class Student {

    protected:
        string studentID;
        string firstName; 
        string lastName;
        string email; 

        int age;// age of the student
        int days[3];// days to complete courses (3) for the term

        string degreeStr(Degree program);

// Requirements D.2.
    public: 

        // Requirements D.2.c 
        Student(string ID, string firstName, string lastName, string email, int age, int days[], Degree program); 
        virtual ~Student();// Requirements D.2.e

        // Requirements D.2.a
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int    getAge();
        int*   getDays();
        virtual Degree getDegreeProgram();// Requirements D.2.f

        // Requirements D.2.b
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setDays(int daysOfCourse1, int daysOfCourse2, int daysOfCourse3);

        virtual void print();// Requirements D.2.d
        

};