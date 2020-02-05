#pragma once
#include "degree.h"
#include "student.h"

// Requirements D.3.
class NetworkStudent : public Student {

    Degree program;

    public:

    NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int* days, Degree program);
    virtual ~NetworkStudent();

    Degree getDegreeProgram() override;
    void print() override;
};