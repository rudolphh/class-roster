#pragma once
#include "degree.h"
#include "student.h"

// Requirements D.3.
class SoftwareStudent : public Student {

    Degree program;

    public:

    SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int* days, Degree program);
    virtual ~SoftwareStudent();

    Degree getDegreeProgram() override;
    void print() override;
    
};