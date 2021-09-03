#include "deg.cpp"

int main(){
    Student a;
    a.diplayStudentData(); 
    cout << "------------------\n";

    a.setIdNum(1);
    a.setLastName("Phan");
    a.setGradePointAverage(3.4);
    a.diplayStudentData();
    cout << "------------------\n";
    Student b = Student(12,"CTK");
    b.diplayStudentData();
    system("pause");
}