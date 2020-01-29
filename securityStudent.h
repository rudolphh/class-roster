#pragma once
#include "degree.h"
#include "student.h"

// Requirements D.3.
class SecurityStudent : public Student {

    Degree program;

    public:

    SecurityStudent(string ID, string firstName, string lastName, string email, int age, int* days, Degree program);
    ~SecurityStudent();

    Degree getDegreeProgram() override;
    void setDegreeProgram(Degree program) override;

    void print() override;

};