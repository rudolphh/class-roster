#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int* days, Degree program) 
                    : Student (studentID, firstName, lastName, email, age, days, program) {
    this->program = NETWORK;
}

NetworkStudent::~NetworkStudent(){}

Degree NetworkStudent::getDegreeProgram(){ return program; }

void NetworkStudent::print() { 
    
    Student::print();
    std::cout<<"Degree Program: "<<degreeStr(getDegreeProgram())<<std::endl;
    
}

