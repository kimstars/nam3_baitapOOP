#include "HinhHoc.h"

class HCN : public HinhHoc
{
private:
    double ChieuDai;
    double ChieuRong;

public:
    HCN();
    HCN(int x, int y);
    void show();
    void Nhap();
    virtual void setDienTich();
    void Print();
};

HCN::HCN()
{
    ChieuDai = ChieuRong = 0;
}
HCN::HCN(int x, int y)
{
    this->ChieuDai = x;
    this->ChieuRong = y;
}

void HCN::show()
{
    cout << "Chieu dai :" << ChieuDai << endl;
    cout << "Chieu rong: " << ChieuRong << endl;
}

void HCN::Nhap()
{
    cout << "Nhap chieu dai";
    cin >> this->ChieuDai;
    cout << "Nhap chieu rong";
    cin >> this->ChieuRong;
}

void HCN::setDienTich()
{
    dientich = this->ChieuDai * this->ChieuRong;
}

void HCN::Print()
{
    cout << "Hinh chu nhat : " << ChieuDai << " : " << ChieuRong;
    HinhHoc::Print();
}