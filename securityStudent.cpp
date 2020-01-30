#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int* days, Degree program) 
                    : Student (studentID, firstName, lastName, email, age, days, program) {
    this->program = SECURITY;
}

SecurityStudent::~SecurityStudent(){}

Degree SecurityStudent::getDegreeProgram(){ return program; }

void SecurityStudent::print() {     
    Student::print();
    std::cout<<"Degree Program: "<<degreeStr(getDegreeProgram())<<std::endl;
}