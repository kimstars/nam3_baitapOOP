#pragma once
#include <bits/stdc++.h>
using namespace std;

class CNSX
{
    private:
        string name;
        int Soluongsp;
    public:
        CNSX(){
            name = "";
            Soluongsp = 0;
        }
        CNSX(string name, int soluong){
            this->name = name;
            this->Soluongsp = soluong;
        }
        void Nhap(){
            cout << "Nhap ten nhan vien: ";
            cin >> this->name;
            cout << "Nhap So luong san pham nhan vien lam ra : ";
            cin >> this->Soluongsp;
        }
        string getName(){
            return name;
        }
        int getSoluong(){
            return Soluongsp;
        }

        int tinhLuong(){
            return 5000*Soluongsp;
        }



};