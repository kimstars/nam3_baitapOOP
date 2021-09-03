#include <iostream>
#include<string>
#pragma once
using namespace st                                                                                                                                      , d;

class Student{
    private:
        int idNum;
        string lastName;
        double gradePointAverage;
    public:
        Student(){};
        Student(int idNum, string lastName): idNum(idNum), lastName(lastName){};
        void diplayStudentData();
        void setIdNum(int);
        void setLastName(string lastName); 
        void setGradePointAverage(double gpa);
};


