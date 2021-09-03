#include "HinhHoc.h"

#define Pi 3.14

class Tron : public HinhHoc
{
private:
    double R;

public:
    Tron();

    Tron(double R);

    virtual void setDienTich();

    void Nhap();

    void Print();

};
Tron::Tron()
{
    R = 0;
}

Tron::Tron(double R)
{
    this->R = R;
}

void Tron::setDienTich()
{
    dientich = Pi * pow(R, 2);
}

void Tron::Nhap()
{
    cout << "Nhap ban kinh: ";
    cin >> R;
}
void Tron::Print()
{

    cout << "Hinh tron: R =  " << R << endl;
    HinhHoc::Print();
}