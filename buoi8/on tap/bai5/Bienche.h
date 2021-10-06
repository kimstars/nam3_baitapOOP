#include "Nhansu.h"


class BienChe : public NhanSu
{
private:
    int year;
public:
    BienChe();
    void Nhap();
    void Print();
    
    
    
};

BienChe::BienChe()
{
    NhanSu();
    year = 0;
}

void BienChe::Nhap()
{
    NhanSu::Nhap();
    cout << "Nhap so nam bien che : ";
    cin >> year;
}

void BienChe::Print()
{
    cout << "NV Bien che | ";
    NhanSu::Print();
    cout << setw(10) << "So nam bien che : ";
    cout << year << endl; 
}

