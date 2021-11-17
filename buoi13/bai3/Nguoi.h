#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Nguoi
{
protected:
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
        cout << "\nHay Nhap Ten: ";
        fflush(stdin);
        getline(cin, name);
        cout << "\nHay Nhap Nam Sinh: ";
        fflush(stdin);
        cin >> namsinh;
        tinhtuoi();
        cout << "\nHay Nhap Que Quan: ";
        fflush(stdin);
        getline(cin, quequan);
    }

    friend ostream &operator<<(ostream &, Nguoi &);
    friend istream &operator>>(istream &, Nguoi &);

    void tinhtuoi()
    {
        tuoi = 2021 - namsinh;
    }
    void Xuat()
    {
        cout << left << "Ten: " << setw(15) << name;
        cout << "| Nam Sinh: " << setw(5) << namsinh;
        cout << "| Dia Chi : " << setw(20) << quequan;
        cout << "| Tuoi: " << setw(5) << tuoi;
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
    int getTuoi()
    {
        return tuoi;
    }
};

ostream &operator<<(ostream &os, Nguoi &p)
{

    cout << left << "Ten: " << setw(15) << p.name;
    cout << "| Nam Sinh: " << setw(5) << p.namsinh;
    cout << "| Dia Chi : " << setw(20) << p.quequan;
    cout << "| Tuoi: " << setw(5) << p.tuoi;

}

istream &operator>>(istream &is, Nguoi &p)
{
    cout << "\nHay Nhap Ten: ";
    fflush(stdin);
    getline(is, p.name);
    cout << "\nHay Nhap Nam Sinh: ";
    fflush(stdin);
    is >> p.namsinh;
    p.tinhtuoi();
    cout << "\nHay Nhap Que Quan: ";
    fflush(stdin);
    getline(is, p.quequan);
}