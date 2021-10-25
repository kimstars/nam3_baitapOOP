#pragma once
#include <bits/stdc++.h>
using namespace std;

class Hocvien
{
private:
    char name[20];
    int birth;
    double diemToan;
    double diemVan;
    double diemAnh;
    double diemTB;

public:
    Hocvien(){};
    Hocvien(char* name, int birth, double diemToan, double diemVan, double diemAnh)
    {
        strcpy(this->name,name);
        birth = birth;
        diemToan = diemToan;
        diemVan = diemVan;
        diemAnh = diemAnh;
    }
    ~Hocvien(){};
    void Nhap();
    void Xuat();
    void tinhdiemtb();

    double getdiemtb();
    char* getName();

    friend istream &operator>>(istream &, Hocvien &);
    friend ostream &operator<<(ostream &, Hocvien &);

    bool duoi5();
    int XepLoai();
    friend void chuanhoa(char *);
};
void chuanhoa(char *a)
{
    int n = strlen(a);
    int i;
    if (a[0] != 32)
    {
        if (a[0] > 96 && a[0] < 123)
        {
            a[0] -= 32;
        }
    }
    for (i = 1; i < n; i++)
    {
        if (a[i] == 32)
        {
            if (a[i + 1] > 96 && a[i + 1] < 123)
            {
                a[i + 1] -= 32;
            }
        }
    }
}

istream &operator>>(istream &is, Hocvien &h)
{
    cout << "Nhap ho ten :";
    fflush(stdin);
    fgets(h.name, 20, stdin);
    chuanhoa(h.name);
    cout << "Nhap nam sinh : ";
    is >> h.birth;

    cout << "Nhap diem mon Toan : ";
    is >> h.diemToan;

    cout << "Nhap diem mon Van : ";
    is >> h.diemVan;

    cout << "Nhap diem mon Anh : ";
    is >> h.diemAnh;
    return is;
}
void Hocvien::Nhap()
{
    cout << "Nhap ho ten :";
    fflush(stdin);
    fgets(name,20, stdin);
    strtok(name, "\n");
    chuanhoa(name);
    cout << "Nhap nam sinh : ";
    cin >> birth;

    cout << "Nhap diem mon Toan : ";
    cin >> diemToan;

    cout << "Nhap diem mon Van : ";
    cin >> diemVan;

    cout << "Nhap diem mon Anh : ";
    cin >> diemAnh;
    tinhdiemtb();
}
void Hocvien::tinhdiemtb()
{
    diemTB = (diemToan + diemVan + diemAnh) / 3;
}

void Hocvien::Xuat()
{
    cout << "\n- Ho va ten : " <<left<< setw(20) << name;
    cout << "- Nam sinh : " << setw(10) << birth;
    cout << "- Diem trung binh : " << setw(10) << diemTB << endl;
}

char * Hocvien::getName()
{
    return name;
}
bool Hocvien::duoi5()
{
    if (diemToan < 5 || diemVan < 5 || diemAnh < 5)
        return 0;
    return 1;
}
double Hocvien::getdiemtb()
{
    return diemTB;
}
int Hocvien::XepLoai()
{
    if (duoi5())
    {
        if (diemTB > 7)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 3;
    }
}

ostream &operator<<(ostream &os, Hocvien &h)
{
    os << "\n- Ho va ten : " <<left<< setw(25) << h.name;
    os  << "- Nam sinh : " << setw(15)<< h.birth;
    os  << "- Diem trung binh : " << setw(15) << h.diemTB << endl;
    return os;
}

