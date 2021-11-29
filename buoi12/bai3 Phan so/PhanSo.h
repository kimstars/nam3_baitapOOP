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
    
    PhanSo toigian();
    void Toigian();
    
    PhanSo operator+(int d);
//    friend PhanSo operator-(PhanSo &p, int d);
    PhanSo operator*(int d);
    PhanSo operator/(int d);

    PhanSo operator+(const PhanSo &p);
    PhanSo operator-(const PhanSo &p);
    PhanSo operator*(const PhanSo &p);
    PhanSo operator/(const PhanSo &p);

    double hieu(PhanSo &p);
    
    // void operator=(const PhanSo &p);
    bool operator>(const PhanSo &p);
    bool operator<(const PhanSo &p);
    bool operator==(PhanSo &f);

    PhanSo operator++(int);
    
    PhanSo operator++(){
    	a += b;
    	Toigian();
    	return *this;
	}
    void operator+=(const PhanSo &f);
    void operator-=(const PhanSo &f);
    void operator*=(const PhanSo &f);
    void operator/=(const PhanSo &f);

    int gcd(int a, int b);
    
    double ketqua(){
        return a/b;
    }

    int Tu(){
        return a;
    }
    int Mau(){
        return b;
    }
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

    p.Toigian();
    return is;
}



int PhanSo::gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

PhanSo PhanSo::toigian()
{
    PhanSo p;
    int u = gcd(a, b);
    p.a = a / u;
    p.b = b / u;
    return p;
}
void PhanSo::Toigian(){
    int u = gcd(a, b);
    a /=  u;
    b /=  u;
}


PhanSo PhanSo::operator+(const PhanSo &p)
{
    a = a * p.b + b * p.a;
    b = b * p.b;
    Toigian();
    return (*this);
}

PhanSo PhanSo::operator-(const PhanSo &p)
{
    a = a * p.b - b * p.a;
    b = b * p.b;
    Toigian();
    return (*this);
}
PhanSo PhanSo::operator/(const PhanSo &p)
{
    
    a  *= p.b;
    b *= p.a;
    Toigian();
    return (*this);
}
PhanSo PhanSo::operator+(int d){
    a += b * d;
    Toigian();
    return (*this);
}

//PhanSo operator-(PhanSo p,int d){
//    p.a -= p.b * d;
//    p.toigian();
//    return p;
//}
PhanSo PhanSo::operator*(int d){
    a *= d;
    Toigian();
    return (*this);
}

PhanSo PhanSo::operator/(int d){
    b *= d;
    Toigian();
    return (*this);
}


double PhanSo::hieu(PhanSo &p){
    PhanSo p1;
    p1.a = a * p.b - b * p.a;
    p1.b = b * p.b;
    return p1.ketqua();
}


PhanSo PhanSo::operator*(const PhanSo &p)
{
    a = a * p.a;
    b = b * p.b;
    Toigian();
    return (*this);
}

// void PhanSo::operator=(const PhanSo &p)
// {
//     a = p.a;
//     b = p.b;
// }

bool PhanSo::operator>(const PhanSo &p)
{
    int cmp = a * p.b - b * p.a;
    return cmp > 0;
}

bool PhanSo::operator<(const PhanSo &p)
{
    int cmp = a * p.b - b * p.a;
    return cmp < 0;
}

bool PhanSo::operator==(PhanSo &p){
    int cmp = a * p.b - b * p.a;
    return cmp == 0;
}

PhanSo PhanSo::operator++(int){
    a += b;
    Toigian();
    return (*this);
}


void PhanSo::operator+=(const PhanSo &p){
    a = a * p.b + b * p.a;
    b = b * p.b;
    Toigian();
}
void PhanSo::operator-=(const PhanSo &p){
    a = a * p.b - b * p.a;
    b = b * p.b;
    Toigian();
}

void PhanSo::operator*=(const PhanSo &p){
    a = a * p.a;
    b = b * p.b;
    Toigian();
}

void PhanSo::operator/=(const PhanSo &p){
    a = a * p.b;
    b = b * p.a;
    Toigian();
}





