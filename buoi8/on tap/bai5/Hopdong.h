#include "Nhansu.h"


class HopDong : public NhanSu
{
private:
    string loaihopdong;

public:
    HopDong();
    void Nhap();
    void Print();
    
    
    
};

HopDong::HopDong()
{
    NhanSu();
    loaihopdong = "";
}

void HopDong::Nhap()
{
    NhanSu::Nhap();
    cout << "Nhap loai hop dong : ";
    fflush(stdin);
    getline(cin,loaihopdong);
}

void HopDong::Print()
{
    cout << "NV Hop dong | ";
    NhanSu::Print();
    cout << setw(10) << "Loai hop dong : ";
    cout << loaihopdong << endl; 
}

