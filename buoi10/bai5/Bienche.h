#include "Nhansu.h"


class BienChe : public NhanSu
{
private:
    double base;
    double phucapcv;
public:
    BienChe();
    void Nhap();
    void Print();
    void TinhLuong();
};

BienChe::BienChe()
{
    base = phucapcv = 0;
}

void BienChe::Nhap()
{
    cout << "Nhap Nhan vien BIEN CHE \n";
    NhanSu::Nhap();
    cout << "Nhap he so luong : ";
    cin >> base;
    while (cin.fail())
    {
        cout << "Vui long nhap so thuc. \n";
        cout << "Nhap he so luong : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> base;
    }
    cout << "Nhap phu cap chuc vu : ";
    cin >> phucapcv;
    while (cin.fail())
    {
        cout << "Vui long nhap so tu nhien. \n";
        cout << "Nhap phu cap chuc vu : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> phucapcv;
    }
    TinhLuong();

}
void BienChe::TinhLuong(){
    luong = base*1300 + phucapcv;
}

void BienChe::Print()
{
    cout << "NV Bien che | ";
    NhanSu::Print();
    cout  << "He so luong : "<< setw(10) << base <<  "phu cap :"<<setw(10) << phucapcv; 
    cout << ", Luong : "<<setw(10) << luong << endl;
}

