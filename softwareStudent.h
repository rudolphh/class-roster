#pragma once
#include "degree.h"
#include "student.h"

// Requirements D.3.
class SoftwareStudent : public Student {

    Degree program;

    public:

    SoftwareStudent(string ID, string firstName, string lastName, string email, int age, int* days, Degree program);
    ~SoftwareStudent();

    Degree getDegreeProgram() override;
    void setDegreeProgram(Degree program) override;

    void print() override;
    
};