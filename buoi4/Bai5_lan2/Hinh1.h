#pragma once
#include <bits/stdc++.h>

using namespace std;

class Hinh
{
protected:
    double dientich;

public:
    double getDientich(){
        return dientich;
    }
    virtual void Nhap()=0;
    virtual void setDienTich() = 0;
    virtual void Print(){
        cout <<"In ra : ";
    }

};
