#include <iostream>
#include <sstream>
#include <vector>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using std::cout;
using std::endl;
using std::stringstream;
using std::vector;


const string studentData[] = { 
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Rudy,Hernandez,rhern87@wgu.edu,37,40,7,15,SOFTWARE" 
};

vector<string> parseFields(string data);
Degree enumDegree(string str);


///////////////////// Requirement F (C++ requires int main)
int main(){

    cout<<"Scripting and Programming - Applications – C867"<<endl;
    cout<<"C++"<<endl;
    cout<<"Student ID: #000628800"<<endl;
    cout<<"Rudy Hernandez"<<endl;

    const int numStudents = sizeof(studentData) / sizeof(studentData[0]);

    Roster classRoster(numStudents);

    vector<string> parsedRow;
    for (int row = 0; row < numStudents; row++){ 
        parsedRow = parseFields(studentData[row]);
        classRoster.add(parsedRow[0], parsedRow[1], parsedRow[2], parsedRow[3], stoi(parsedRow[4]),
                        stoi(parsedRow[5]), stoi(parsedRow[6]), stoi(parsedRow[7]), enumDegree(parsedRow[8]));
    }

    classRoster.printAll();

    return 0;

}// end int main()


/////////////////// Roster class methods

void Roster::add(string studentID, string firstName, string lastName, string email, int age, 
                int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program){

    Student* student;
    int* days { new int[3] { daysInCourse1, daysInCourse2, daysInCourse3 } };

    switch (program) {
        case NETWORK : student = new NetworkStudent(studentID, firstName, lastName, email, age, days, program ); break;
        case SECURITY: student = new SecurityStudent(studentID, firstName, lastName, email, age, days, program ); break;
        case SOFTWARE: student = new SoftwareStudent(studentID, firstName, lastName, email, age, days, program ); break;
    }

    for (int i = 0; i < max; i++){
        if (!classRosterArray[i]) {  classRosterArray[i] = student; break; }
    }
}


void Roster::remove(string studentID){ }
void Roster::printAll(){ 
    for(int i = 0; i < max; i++){
        if(classRosterArray[i]) classRosterArray[i]->print();
    }
 }
void Roster::printDaysInCourse(string studentID){ }
void Roster::printInvalidEmails(){ }
void Roster::printByDegreeProgram(int degreeProgram){ }


Roster::Roster(int numStudents){ classRosterArray = new Student*[numStudents]; max = numStudents; }
Roster::~Roster(){}

///////////////////////  HELPERS
vector<string> parseFields(string dataRow){

    vector<string> dataFields;
    stringstream ss; 
    string fieldStr;

    ss.str(dataRow);
 
    while(getline(ss, fieldStr, ',')) dataFields.push_back(fieldStr);

    return dataFields;
}

Degree enumDegree(string str){
    return str == "NETWORK" ? NETWORK : (str == "SECURITY" ? SECURITY : (str == "SOFTWARE" ? SOFTWARE : UNDEFINED));
}

