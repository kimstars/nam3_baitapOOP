#pragma once
#include <bits/stdc++.h>
using namespace std;

class HCN
{
private:
    double ChieuDai;
    double ChieuRong;

public:
    HCN()
    {
        ChieuDai = ChieuRong = 0;
    }
    HCN(int x ,int y)
    {
        this->ChieuDai = x;
        this->ChieuRong = y;
    }

    void show()
    {
        cout << "Chieu dai :" << ChieuDai << endl;
        cout << "Chieu rong: "<< ChieuRong << endl;
    }

    void Nhap()
    {
        cout << "Nhap chieu dai" ;
        cin >> this->ChieuDai;
        cout << "Nhap chieu rong" ;
        cin >> this->ChieuRong;

    }
    
    double dientich(){
        return this->ChieuDai * this->ChieuRong;
    }
 
};