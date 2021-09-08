#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

class Phanso
{

public:
    int a, b;
    Phanso(int a, int b) : a(a), b(b){};
    Phanso()
    {
        a = b = 0;
    };
    void nhap();
    void in();
    int gcd(int, int);
    Phanso toigian();
    Phanso operator+(const Phanso &p);
    Phanso operator-(const Phanso &p);
    Phanso operator*(const Phanso &p);
    void operator=(const Phanso &p);
    bool operator>(const Phanso &p);

};
void Phanso::nhap()
{

    int at, bt;
    cout << "nhap tu so : ";
    cin >> at;
    do
    {
        cout << "nhap mau so : ";
        cin >> bt;
        if (bt == 0)
        {
            cout << "b khac 0 !!! pls\n";
        }
    } while (bt == 0);

    Phanso temp(at,bt);
    temp = temp.toigian();
    a= temp.a;
    b = temp.b;
}

void Phanso::in()
{
    if (b == 1)
    {
        cout << a;
    }
    else
    {
        cout << a << "/" << b;
    }
    cout << endl;
}

int Phanso::gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

Phanso Phanso::toigian()
{
    Phanso p;
    int u = gcd(a, b);
    p.a = a / u;
    p.b = b / u;
    return p;
}

Phanso Phanso::operator+(const Phanso &p)
{
    Phanso p1;
    p1.a = a * p.b + b * p.a;
    p1.b = b * p.b;
    return p1.toigian();
}

Phanso Phanso::operator-(const Phanso &p)
{
    Phanso p1;
    p1.a = a * p.b - b * p.a;
    p1.b = b * p.b;
    return p1.toigian();
}

Phanso Phanso::operator*(const Phanso &p)
{
    Phanso p1;
    p1.a = a * p.a;
    p1.b = b * p.b;
    return p1.toigian();
}

void Phanso::operator=(const Phanso &p)
{
    a = p.a;
    b = p.b;
}




bool Phanso::operator>(const Phanso &p){
    double cmp = a* p.b - b * p.a;
    return cmp > 0;
}


