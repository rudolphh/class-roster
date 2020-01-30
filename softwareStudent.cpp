#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int* days, Degree program) 
                    : Student (studentID, firstName, lastName, email, age, days, program) {
    this->program = SOFTWARE;
}

SoftwareStudent::~SoftwareStudent(){}

Degree SoftwareStudent::getDegreeProgram(){ return program; }

void SoftwareStudent::print() { 
    Student::print();
    std::cout<<"Degree Program: "<<degreeStr(getDegreeProgram())<<std::endl; 
}