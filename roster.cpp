#include <iostream>
#include <sstream>
#include <vector>
#include "roster.h"

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

vector<string> parseFields(string data);// helper

int main(){

    cout<<"Scripting and Programming - Applications – C867"<<endl;
    cout<<"C++"<<endl;
    cout<<"Student ID: #000628800"<<endl;
    cout<<"Rudy Hernandez"<<endl;

    //Roster classRoster;

    vector<string> dataFields[5];
    stringstream ss; 
    string field;

    for (int row = 0; row < 5; row++){

        dataFields[row] = parseFields(studentData[row]);
        ss.str(studentData[row]);

        for(int x = 0; x < 9; x++) cout<<dataFields[row][x]<<" ";

        cout<<endl;

        ss.clear();
    }

    return 0;

}// end int main()

vector<string> parseFields(string dataRow){

    vector<string> dataFields;
    stringstream ss; 
    string fieldStr;

    ss.str(dataRow);
 
    while(getline(ss, fieldStr, ',')) dataFields.push_back(fieldStr);

    return dataFields;
}