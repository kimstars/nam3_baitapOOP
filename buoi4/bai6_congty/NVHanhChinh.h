#pragma once
#include <bits/stdc++.h>
#include "Nhanvien.h"
using namespace std;

class NVHC : public NhanVien
{
    private:
        double HSluong;
    public:
        NVHC(){
            name = "";
            HSluong = 0;
        }
        NVHC(string name, double soluong){
            name = name;
            this->HSluong = soluong;
        }

        void Nhap(){
            cout << "Nhap ten nhan vien: ";
            cin >> name;
            cout << "Nhap he so luong : ";
            cin >> this->HSluong;
        }

        string getName(){
            return name;
        }
        double getHSluong(){
            return HSluong;
        }

        double tinhLuong(){
            return 1300*HSluong;
        }



};