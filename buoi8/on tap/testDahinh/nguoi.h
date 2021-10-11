#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Nguoi
{
protected:
    string name;
    int age;

public:
    virtual void Nhap(){
        cout << "Nhap ten : ";
        fflush(stdin);
        getline(cin, name);
        cout << "Nhap tuoi : ";
        cin >> age;
    }

    virtual void Xuat(){
        cout << "Name : " << name << ", Tuoi : " << age ;
    }


};
