#include <bits/stdc++.h>
using namespace std;

class SoPhuc
{

public:
    int Phanthuc, Phanao;

public:
    SoPhuc()
    {
        Phanthuc = 0;
        Phanao = 0;
    }
    // 1
    SoPhuc(int thuc)
    {
        Phanthuc = thuc;
        Phanao = 0;
    }
    // 2
    SoPhuc(int thuc, int ao)
    {
        Phanthuc = thuc;
        Phanao = ao;
    }

    // 6 xuat <<xuat SoPhuc
    friend ostream &operator<<(ostream &xuat, SoPhuc &sp);
    // 6 nhap >> sophuc
    friend istream &operator>>(istream &nhap, SoPhuc &sp);
    // Gan sophuc=sophuc sp
    SoPhuc operator=(SoPhuc sp);
};

// 6 nhap >> sophuc
istream &operator>>(istream &nhap, SoPhuc &sp)
{
    cout << "a= ";
    nhap >> sp.Phanthuc;
    cout << "b= ";
    nhap >> sp.Phanao;
    return nhap;
}

ostream &operator<<(ostream &xuat, SoPhuc &sp)
{
    if (sp.Phanthuc != 0)
        xuat << sp.Phanthuc;
    if (sp.Phanao > 0)
    {
        cout << "+";
        xuat << sp.Phanao;
        cout << "i";
    }
    if (sp.Phanao < 0)
    {
        xuat << sp.Phanao;
        cout << "i";
    }
    return xuat;
}
// Gan sophuc=sophuc sp
SoPhuc SoPhuc::operator=(SoPhuc sp)
{
    Phanthuc = sp.Phanthuc;
    Phanao = sp.Phanao;
}