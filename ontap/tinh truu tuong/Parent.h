#include <bits/stdc++.h>

using namespace std;

class Parent{
private:
    string name;
    int age;
public:
    Parent();
    ~Parent(){};

    virtual void thongtin(){
        cout << "Ten : " << name << "| Tuoi : " << age;
    }
    virtual void Nhap(){
        cout << "Nhap ten : ";
        fflush(stdin);
        getline(name);
        cout <<"Nhap tuoi :";
        cin >> age;
    }

    friend istream operator>>(istream &, const ); 


};


istream operator(istream &, Parent &a){
    cout << "Nhap ten : ";
    fflush(stdin);
    getline(in, a.name);
    cout <<"Nhap tuoi :";
    in >> age;
    return in;
}

