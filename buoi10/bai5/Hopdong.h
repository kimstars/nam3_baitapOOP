#include "Nhansu.h"


class HopDong : public NhanSu
{
private:
    double mucluong;
    int songaynghi;
    double bonus;

public:
    HopDong();
    void Nhap();
    void Print();
    void TinhLuong();
};

HopDong::HopDong()
{
    mucluong= bonus = 0;
    songaynghi = 0;
}

void HopDong::Nhap()
{
    cout << "Nhap nhan vien HOP DONG \n";
    NhanSu::Nhap();
    cout << "Nhap muc luong cua "<< getName() << ": " ;
    cin >> mucluong;
    cout << "Nhap so ngay nghi "<< getName() << ": " ;
    cin >> songaynghi;
    cout << "Nhap tien thuong cua "<< getName() << ": " ;
    cin >> bonus;
    TinhLuong();
}

void HopDong::Print()
{
    cout << "NV Hop dong | ";
    NhanSu::Print();
    cout << ", Muc luong : "<<setw(10)<< mucluong ;
    cout <<  ", Nghi : " <<setw(5)<< songaynghi ;
    cout <<  ", Thuong : " <<setw(10)<< bonus;
    cout <<  ", Tong luong : " <<setw(10)<< luong << endl;
}


void HopDong:: TinhLuong(){
    luong = mucluong - (mucluong * songaynghi)/30 + bonus;
}

