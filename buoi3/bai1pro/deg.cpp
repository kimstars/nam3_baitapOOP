#include "student.h"
#include <iostream>

using namespace std;


void Student::diplayStudentData(){
    cout << "IdNum: " << idNum <<endl;
    cout << "LastName: " << lastName <<endl;
    cout << "GPA: " << gradePointAverage <<endl;
}
void Student::setIdNum(int idNum){
    this->idNum=idNum;
}
void Student :: setLastName(string lastName){
    this->lastName=lastName;
}
void Student :: setGradePointAverage( double gpa){
    this->gradePointAverage=gpa;
}