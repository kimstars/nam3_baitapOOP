#include <bits/stdc++.h>
#pragma once
using namespace std;

class Book
{
protected:
    string name;
    string nxb;
    string id;
    int numPub;

public:
    Book(string name, string nxb, string id, int numPub) : name(name), nxb(nxb), id(id), numPub(numPub){};

    Book()
    {
        name  = nxb = id = "";
        numPub = 0;
    };
    ~Book(){};


    virtual void Nhap()
    {
        cout << "Nhap ten  : ";
        fflush(stdin);
        getline(cin, name);
        cout << "Nha xuat ban  '" << name << "' : ";
        fflush(stdin);
        getline(cin, nxb);
        cout << "Nhap ma an pham " << name << "' : ";
        fflush(stdin);
        getline(cin, id);
        cout << "Nhap so ban phat hanh  '" << name << "' : ";
        cin >> numPub;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap so ban phat hanh  '" << name << "' : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> numPub;
        }
    }



    virtual void Xuat()
    {
        cout << "Ten :  " <<left <<setw(30)<< name << " | ";
        cout << "Ma an pham :" <<setw(10)<< id << " | ";
        cout << "Nha xuat ban :" <<setw(10)<< nxb << " | ";
        cout << "So ban phat hanh :" <<setw(10)<< numPub << " | ";
    }

        
    void setType(string id)
    {
        this->id = id;
    }
    string getType(){
        return id;
    }
    string getName(){
        return name;
    }

    virtual bool CheckType(int type) = 0;

    bool CheckName(string name){
        if(name == this->name) {
            return true;
        }else return false;
    }
};


