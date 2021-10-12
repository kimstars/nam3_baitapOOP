#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<iomanip>
using namespace std;

class Nguoi
{
private:
    string name;
    int namsinh;
    string quequan;
    int tuoi;

public:
    Nguoi()
    {
        name = quequan = "";
        namsinh = tuoi = 0;
    };
    Nguoi(string name, int namsinh, string quequan)
    {
        this->name = name;
        this->namsinh = namsinh;
        this->quequan = quequan;
        tinhtuoi();
    }
    virtual void Nhap()
    {
        fflush(stdin);
        cout << "\nHay Nhap Ten: ";
        getline(cin, name);
        fflush(stdin);
        cout << "\nHay Nhap Nam Sinh: ";
        cin >> namsinh;
        tinhtuoi();
        cout << "\nHay Nhap Que Quan: ";
        fflush(stdin);
        getline(cin, quequan);
    }
    void tinhtuoi()
    {
        tuoi = 2021 - namsinh;
    }
    void Xuat()
    {
        cout <<left <<  "Ten: " << setw(15) << name ;
        cout  << ", Nam Sinh: " << setw(5)<< namsinh;
        cout  << ", Dia Chi Thuong Tru: " <<setw(20)<< quequan ;
        cout << ", Tuoi: " << setw(5) << tuoi ;
    }
    bool operator>(const Nguoi &n)
    {
        if (this->tuoi > n.tuoi)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int getNamsinh()
    {
        return namsinh;
    }
    string getName()
    {
        return name;
    }
    string getQueQuan()
    {
        return quequan;
    }
    int getTuoi(){
        return tuoi;
    }
};
