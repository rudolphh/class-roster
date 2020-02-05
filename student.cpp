#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;

Student::Student(string ID, string firstName, string lastName, string email, int age, int days[], Degree program){
    this->studentID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for(int i = 0; i < 3; i++) this->days[i] = days[i];
}

Student::~Student(){

}

string Student::degreeStr(Degree program){
    switch (program)
    {
        case NETWORK: return "NETWORK";
        case SECURITY: return "SECURITY";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNDEFINED";
    }
}

string Student::getStudentID(){ return studentID; }
string Student::getFirstName(){ return firstName; }
string Student::getLastName(){ return lastName; }
string Student::getEmail(){ return email; }
int    Student::getAge(){ return age; }
int*   Student::getDays(){ return days; }

Degree Student::getDegreeProgram() { }

void Student::print(){
    cout<<getStudentID()<<"\t";
    cout<<"First Name: "<<this->getFirstName()<<"\t";
    cout<<"Last Name: "<<this->getLastName()<<"\t";
    cout<<"Age: "<<this->getAge()<<"\t";
    int* daysIn = this->getDays();
    cout<<"daysInCourse: {"<<std::setw(2)<<daysIn[0]<<", "<<std::setw(2)<<daysIn[1]<<", "<<std::setw(2)<<daysIn[2]<<"} ";

}