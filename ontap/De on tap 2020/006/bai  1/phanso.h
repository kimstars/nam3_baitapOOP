#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

class PhanSo
{
private:
    int a, b;

public:
    PhanSo(int a, int b) : a(a), b(b){};
    PhanSo()
    {
        a = 0;
        b = 1;
    };

    friend ostream &operator<<(ostream &, PhanSo &);
    friend istream &operator>>(istream &, PhanSo &);
    
    
    friend PhanSo operator+(PhanSo &temp,const PhanSo &p);
    // friend PhanSo operator-(PhanSo &p, int d);
    // friend PhanSo operator*(const PhanSo &p);
    // friend PhanSo operator/(const PhanSo &p);





};

ostream &operator<<(ostream &os, PhanSo &p){
    if (p.b == 1)
    {
        os << p.a;
    }
    else
    {
        os << p.a << "/" << p.b;
    }
    os << endl;
    return os;
}

istream &operator>>(istream &is, PhanSo &p){
    int at, bt;
    cout << "Nhap tu so : ";
    is >> p.a;
    do
    {
        cout << "Nhap mau so : ";
        is >> p.b;
        if (p.b == 0)
        {
            cout << "b khac 0 !!! pls\n";
        }
    } while (p.b == 0);

    return is;
}




PhanSo operator+(PhanSo &temp, const PhanSo &p)
{
    temp.a = temp.a * p.b + temp.b * p.a;
    temp.b = temp.b * p.b;
    return temp;
}

PhanSo operator-(const PhanSo &p)
{
    PhanSo temp;
    temp.a = temp.a * p.b - temp.b * p.a;
    temp.b = temp.b * p.b;
    return temp;
}
PhanSo operator/(const PhanSo &p)
{
    PhanSo temp;
    temp.a  *= p.b;
    temp.b *= p.a;
    
    return temp;
}




PhanSo operator*(const PhanSo &p)
{
    PhanSo temp;
    temp.a = temp.a * p.a;
    b = b * p.b;
    
    return (*this);
}



