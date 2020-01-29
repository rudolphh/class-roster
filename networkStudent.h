#pragma once
#include "degree.h"
#include "student.h"

// Requirements D.3.
class NetworkStudent : public Student {

    Degree program;

    public:

    NetworkStudent(string ID, string firstName, string lastName, string email, int age, int* days, Degree program);
    ~NetworkStudent();

    Degree getDegreeProgram() override;
    void setDegreeProgram(Degree program) override;

    void print() override;
};