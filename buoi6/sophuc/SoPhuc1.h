#include "SoPhuc.h"

class SoPhuc1 : public SoPhuc
{

public:
    SoPhuc1():SoPhuc(){};
    SoPhuc1(int thuc, int ao):SoPhuc(thuc, ao){};

    SoPhuc1 operator+(const SoPhuc1 &sp);
    // - -> - 2 SoPhuc1
    SoPhuc1 operator-(SoPhuc1 sp);
    // - -> * 2 SoPhuc1
    SoPhuc1 operator*(SoPhuc1 sp);
    // 4 == so sanh 2 so phuc tra ve dau = khi 2 so bang nhau va dau <> khi 2 so khong bang nhau
    string operator==(SoPhuc1 sp);
    // Gan sophuc=sophuc sp
    SoPhuc1 operator=(SoPhuc1 sp);


    double modul(){
        return sqrt(pow(Phanthuc,2)+pow(Phanao,2));
    }

};


SoPhuc1 SoPhuc1::operator+(const SoPhuc1 &sp)
{
    SoPhuc1 temp;
    temp.Phanthuc = Phanthuc + sp.Phanthuc;
    temp.Phanao = Phanao + sp.Phanao;
    return temp;
}
// - -> - 2 SoPhuc1
SoPhuc1 SoPhuc1::operator-(SoPhuc1 sp)
{
    SoPhuc1 temp;
    temp.Phanthuc = Phanthuc - sp.Phanthuc;
    temp.Phanao = Phanao - sp.Phanao;
    return temp;
}
// - -> * 2 SoPhuc1
SoPhuc1 SoPhuc1::operator*(SoPhuc1 sp)
{ //(a + bi)(c + di)
    SoPhuc1 temp;
    temp.Phanthuc = Phanthuc * sp.Phanthuc - Phanao * sp.Phanao; // (ac - bd)
    temp.Phanao = Phanthuc * sp.Phanao + Phanao * sp.Phanthuc; // (ad + bc)
    return temp;
}

// 4 == so sanh 2 so phuc tra ve dau = khi 2 so bang nhau va dau <> khi 2 so khong bang nhau
string SoPhuc1::operator==(SoPhuc1 sp)
{
    if (Phanthuc == sp.Phanthuc && Phanao == sp.Phanao)
        return "==";
    else{
        cout << sp.Phanthuc << " " << Phanthuc << endl;
        return "<>";
    }
}

// 5 tim vi tri so phuc trong mang

