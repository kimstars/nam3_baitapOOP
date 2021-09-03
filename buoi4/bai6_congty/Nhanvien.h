#pragma once
#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
    private:
        string name;
    public:
        NhanVien(){
            name = "";
        }
        NhanVien(string name, int soluong){
            this->name = name;
        }
        void Nhap(){
            cout << "Nhap ten nhan vien: ";
            cin >> this->name;
        }
        string getName(){
            return name;
        }
        
};