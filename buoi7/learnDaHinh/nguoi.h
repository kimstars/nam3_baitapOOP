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
        cout << "Nhap ho ten :";
        fflush(stdin);
        getline(cin, name);
        name = chuanhoa(name);
        cout << "Nhap nam sinh : ";
        cin >> birth;
        cout << "Nhap gioi tinh : (nam : 1)( nu : 0 )";
        while (cin >> gender && gender != 1 && gender != 0 )
        {
            cout << "Xin loi! Chi co 2 gioi tinh!!\n";
            cout << "Nhap gioi tinh : (nam : 1)( nu : 0 )";
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

    string getName(){
        return name;
    }
    string chuanhoa(string &a);
};


string Nguoi::chuanhoa(string &a)
{
    int n = a.length();
    int i;
    if (a[0] != 32)
    {
        if (a[0] > 96 && a[0] < 123)
        {
            a[0] -= 32;
        }
    }
    for (i = 1; i < n; i++)
    {
        if (a[i] == 32)
        {
            if (a[i + 1] > 96 && a[i + 1] < 123)
            {
                a[i + 1] -= 32;
            }
        }
    }
    return a;
}
