#include <bits/stdc++.h>


using namespace std;

class TinhToan
{
public:
    TinhToan();
    ~TinhToan();
    void tong(int a, int b){
        cout << "a + b = "<< a +b << endl;
    }
    void tong(double a, double b){
        cout << "a + b = "<< a +b << endl;
    }

    void tong(int a, int b, int c){
        cout << "a + b + c= "<< a +b + c << endl;
    }

    void tong(double a, double b, double c){
        cout << "a + b + c= "<< a +b +c << endl;
    }


private:
    int ketqua;
    
};

TinhToan::TinhToan()
{
}

TinhToan::~TinhToan()
{
}