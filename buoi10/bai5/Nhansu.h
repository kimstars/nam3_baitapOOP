#pragma once
#include <bits/stdc++.h>
using namespace std;

class NhanSu
{
private:
    string maNhanSu;
    string name;
    string gender;
protected:
    double luong;
public:
    NhanSu();
    ~NhanSu();
    string getName();
    string getID();
    void setName(string name){
        this->name = name;
    }
    double getLuong();
    virtual void Nhap();
    virtual void Print();
    virtual void TinhLuong() = 0;
    bool checkName(string s){
        if(name == s){
            return 1;
        }else{
            return 0;
        }
    }
};

NhanSu::NhanSu()
{
    name = maNhanSu = gender = "";
}

void NhanSu::Nhap()
{
    cout << "Nhap ten nhan vien: ";
    fflush(stdin);
    getline(cin, name);
    cout << "Nhap ma nhan su : ";
    fflush(stdin);
    getline(cin, maNhanSu);
    // cout << "Nhap nam sinh : ";
    // fflush(stdin);
    // getline(cin, birth);
    cout << "Nhap gioi tinh (Nam/Nu) : ";
    cin >> gender;
}
string NhanSu::getName()
{
    return name;
}

string NhanSu::getID()
{
    return maNhanSu;
}

double NhanSu::getLuong(){
    return luong;
}


void NhanSu::Print()
{

    cout << left <<"Ma :"<< setw(10) << maNhanSu
         <<"Ten :"<< setw(20) << name
        //  <<"Nam sinh :"<< setw(15) << birth
         <<"Gioi tinh :"<< setw(5) << gender  ;
}