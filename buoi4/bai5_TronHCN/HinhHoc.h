#pragma once
#include <bits/stdc++.h>
using namespace std;

class HinhHoc
{

protected:
    double dientich;

public:
    HinhHoc();
    virtual ~HinhHoc();
    void Nhap(){
        
    };
    virtual void setDienTich() = 0;
    double getDienTich();
    virtual void Print();
};


HinhHoc::~HinhHoc()
{
}

double HinhHoc::getDienTich()
{
    return dientich;
};
void HinhHoc::Print()
{
    cout << "  Dien tich = " << dientich << endl;
};