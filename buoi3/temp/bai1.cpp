#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class Student {
    private:
        string name;
        int age;
        string address;
    public:
        Student(){};
        Student(string name): name(name){};
        Student(string name, int age, string address): name(name), age(age), address(address){};

        void setName(string name){
            this->name = name;
        }

        string getName(){
            return name;
        }

        void setAge(int age){
            this->age = age;
        }


        int getAge(){
            return age;
        }

        void setAddress(string address){
            this->address = address;
        }

        string getAddress(){
            return address;
        }
};


int main(){
    
}