#pragma once
#include <bits/stdc++.h>
using namespace std;

class Nguoi
{
private:
    string name;
    int birth;
    bool gender;

public:
    Nguoi(){};
    Nguoi(string name, int birth, bool gender){
        name = name;
        birth = birth;
        gender = gender;
    }
    ~Nguoi(){};
    virtual void Nhap()
    {
        cout << "nhap ho ten :";
        fflush(stdin);
        getline(cin, name);
        cout << "nhap nam sinh : ";
        cin >> birth;
        cout << "nhap gioi tinh : (nam : 1)( nu : 0 )";
        while (cin >> gender && gender != 1 && gender != 0 )
        {
            cout << "Xin loi! Chi co 2 gioi tinh!!\n";
            cout << "nhap gioi tinh : (nam : 1)( nu : 0 )";
        }
    }
    virtual void Xuat()
    {
        cout << "\n- Ho va ten : " << name << endl;
        cout << "- Nam sinh : " << birth << endl;
        cout << "- Gioi tinh : ";
        if(gender){
            cout <<  "Nam" << endl;
        }else{
            cout <<  "Nu" << endl;
        }
    }
};
