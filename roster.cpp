#include <iostream>
#include <sstream>
#include <regex>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using std::cout;
using std::endl;
using std::stringstream;


const string studentData[] = { 
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Rudy,Hernandez,rhern87@wgu.edu,37,40,7,15,SOFTWARE" 
};

vector<string> parseFields(string data);
Degree enumDegree(string str);


///////////////////// Requirement F (C++ requires int main)
int main(){

    // Requirement F.1.
    cout<<"Scripting and Programming - Applications – C867"<<endl;
    cout<<"C++"<<endl;
    cout<<"Student ID: #000628800"<<endl;
    cout<<"Rudy Hernandez"<<endl;


    const int numStudents = sizeof(studentData) / sizeof(studentData[0]);
    Roster classRoster(numStudents);// Requirement F.2.
    vector<string> parsedRow;

    // Requirement F.3.
    for (int row = 0; row < numStudents; row++){ 
        parsedRow = parseFields(studentData[row]);
        classRoster.add(parsedRow[0], parsedRow[1], parsedRow[2], parsedRow[3], stoi(parsedRow[4]),
                        stoi(parsedRow[5]), stoi(parsedRow[6]), stoi(parsedRow[7]), enumDegree(parsedRow[8]));
    }

    // Requirement F.4
    cout<<"\n----- Entire Class Roster"<<endl<<endl;
    classRoster.printAll();
    cout<<endl;

    cout<<"----- Invalid Emails"<<endl<<endl;
    classRoster.printInvalidEmails();
    cout<<endl;

    cout<<"----- Students Average days in course"<<endl<<endl;

    // loop through classRosterArray and for each element:
    vector<string> studentIDs;
    classRoster.getStudentIDs(studentIDs);
    for(int i = 0; i < numStudents; i++){ 
        cout<<"student ID: "<<studentIDs[i]<<", average days in course: ";
        classRoster.printAverageDaysInCourse(studentIDs[i]); 
    }
    cout<<endl;

    cout<<"----- Print by degree program: SOFTWARE"<<endl<<endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout<<endl;

    cout<<"----- Attempting to delete student ID: A3"<<endl<<endl;
    classRoster.remove("A3");
    cout<<"----- Attempted to delete student ID: A3 (again)"<<endl<<endl;
    classRoster.remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    cout<<endl;
    
    classRoster.~Roster();// explicit call to destructor (WRONG)
    return 0;// Requirement F.5 Roster destructor called here

}// end int main()


/////////////////// Roster class methods

void Roster::add(string studentID, string firstName, string lastName, string email, int age, 
                int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program){

    Student* student;
    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    switch (program) {
        case NETWORK : student = new NetworkStudent(studentID, firstName, lastName, email, age, days, program ); break;
        case SECURITY: student = new SecurityStudent(studentID, firstName, lastName, email, age, days, program ); break;
        case SOFTWARE: student = new SoftwareStudent(studentID, firstName, lastName, email, age, days, program ); break;
    }

    for (int i = 0; i < max; i++){
        if (!classRosterArray[i]) {  classRosterArray[i] = student; break; }
    }
}


void Roster::remove(string studentID){ 

    for(int i = 0; i < max; i++){
        if(classRosterArray[i]){
            if(classRosterArray[i]->getStudentID() == studentID){
                delete classRosterArray[i]; classRosterArray[i] = nullptr; return;
            }
        }
    }

    cout<<"Student with this ID was not found."<<endl;
}

void Roster::printAll(){ 
    for(int i = 0; i < max; i++){
        if(classRosterArray[i]) classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID){

    for(int i = 0; i < max; i++){
        if(classRosterArray[i]->getStudentID() == studentID){
            int* day = classRosterArray[i]->getDays();
            cout<<((double)(day[0]+day[1]+day[2])/3) <<endl;
        }
    }
}


bool validEmail(string email)
{
    // won't work for variety of emails including multiple periods (e.g. r.hern.87@wgu.edu)
    // combining the first two groups (in the expression) solves this but can cause backtracking delay
    const std::regex expression("(\\w+)(\\.)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, expression);
}

void Roster::printInvalidEmails(){

    string currEmail;

    for(int i = 0; i < max; i++){
        if(classRosterArray[i]){
            currEmail = classRosterArray[i]->getEmail();
            if(!validEmail(currEmail)){
                cout<<currEmail<<endl;
            }
        }
    }
}

void Roster::printByDegreeProgram(int degreeProgram){

    for(int i = 0; i < max; i++){
        if(classRosterArray[i]){
            if(classRosterArray[i]->getDegreeProgram() == degreeProgram){
                classRosterArray[i]->print();
            }
        }
    }

}

void Roster::getStudentIDs(vector<string>& studentIDs){
    
    for(int i = 0; i < max; i++){ studentIDs.push_back(classRosterArray[i]->getStudentID()); }
}

Roster::Roster(int numStudents){ classRosterArray = new Student*[numStudents]; max = numStudents; }
Roster::~Roster(){

    //Basically have to make this check to account for explicit destructor call (WRONG)
    if(!classRosterArray){
        for (int i = 0; i < max; i++) delete this->classRosterArray[i];// free allocated memory of derived objects
        delete this->classRosterArray;// free allocated memory of array of Student pointers
    }
}

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

