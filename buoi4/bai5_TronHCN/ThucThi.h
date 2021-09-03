#include "Tron.h"
#include "Tamgiac.h"
#include "HCN.h"
#include "hinhhoc.h"

class ThucThi{
    private:
        vector<HinhHoc*> hinhhoc;
        int n1, n2, n3;

    public:
    ThucThi(){
        hinhhoc.resize(0);
        n1= n2= n3 =0;
    }
        void Nhap(vector<HinhHoc*> &hinhhoc);
        void thucthi(){
            Nhap(hinhhoc);
        }
};

void ThucThi::Nhap(vector<HinhHoc*> &hinhhoc){
    cout << "Nhap so hinh chu nhat : ";
    cin >> n1;
    cout << "Nhap so hinh tam giac : ";
    cin >> n2;
    cout << "Nhap so hinh tron : ";
    cin >> n3;

    for (int i = 0; i < n1; i++) //array hinh chu nhat
    {
        hinhhoc.push_back(new HCN());
        hinhhoc[hinhhoc.size() - 1]->Nhap();
    }
    for (int i = 0; i < n2; i++) //array hinh tam giac
    {
        hinhhoc.push_back(new Tamgiac());
        hinhhoc[hinhhoc.size() - 1]->Nhap();
    }

    for (int i = 0; i < n3; i++) //array hinh tron
    {
        hinhhoc.push_back(new Tron());
        hinhhoc[hinhhoc.size() - 1]->Nhap();
    }

    for (int i = 0; i < n1+n2+n3; i++)
    {
        hinhhoc[i]->Print();
    }

}