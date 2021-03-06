#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
        getline(cin, quequan);
        fflush(stdin);
    }
    void tinhtuoi()
    {
        tuoi = 2021 - namsinh;
    }
    void Xuat()
    {
        cout << "\nTen la: " << name << endl;
        cout << "\nNgay Thang Nam Sinh: " << namsinh << endl;
        cout << "\nDia Chi Thuong Tru: " << quequan << endl;
        cout << "\nTuoi : " << tuoi << endl;
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
    int getTuoi()
    {
        return tuoi;
    }
    string getName()
    {
        return name;
    }
    string getQueQuan()
    {
        return quequan;
    }
};
