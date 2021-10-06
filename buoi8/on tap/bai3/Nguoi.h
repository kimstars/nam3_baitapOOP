#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Nguoi
{
public:
    string name;
    string ngaysinh;
    string quequan;
    int tuoi;

public:
    Nguoi() {};
    Nguoi(string name, string ngaysinh, string quequan, int tuoi)
    {
        this->name = name;
        this->ngaysinh = ngaysinh;
        this->quequan = quequan;
        this->tuoi = tuoi;
    }
    virtual void Nhap()
    {
        fflush(stdin);
        cout << "\nHay Nhap Ten: ";
        getline(cin, name);
        fflush(stdin);
        cout << "\nHay Nhap Ngay Sinh: ";
        getline(cin, ngaysinh);
        fflush(stdin);
        cout << "\nHay Nhap Que Quan: ";
        getline(cin, quequan);
        fflush(stdin);
        cout << "\nHay Nhap Tuoi: ";
        cin >> tuoi;
    }
    void Xuat()
    {
        cout << "\nTen la: " << name;
        cout << "\nNgay Thang Nam Sinh: " << ngaysinh;
        cout << "\nDia Chi Thuong Tru: " << quequan;
        cout << "\nTuoi La: " << tuoi;
    }
    int operator>(Nguoi n)
    {
        Nguoi m;
        if (m.tuoi > n.tuoi)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int operator<(Nguoi n)
    {
        Nguoi m;
        if (m.tuoi < n.tuoi)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }
    int operator=(Nguoi n)
    {
        Nguoi m;
        if (m.tuoi == n.tuoi)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int getTuoi()
    {
        return tuoi;
    }
    string getNgaysinh()
    {
        return ngaysinh;
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
