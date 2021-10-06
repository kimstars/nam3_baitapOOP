#include "dausach.h"


class Quanlydausach : public dausach{
private:
    vector<dausach*> listDausach;
    int soluongDausach;
public :
    Quanlydausach(){
        listDausach.resize(0);
        soluongDausach = 0;
    }

    void Nhap(){
        cout << "So luong dau sach muon nhap : ";
        cin >> soluongDausach;
        cout << "Nhap " << soluongDausach <<  " dau sach : \n";
        for (int i = 0; i < soluongDausach; i++)
        {
            listDausach.push_back(new dausach());
            listDausach[listDausach.size()-1]->Nhap();
        }
        
    }
    

    void Xuat(){
        cout << "So luong dau sach  : ";
        cout <<  soluongDausach;
        cout << "Nhap " << soluongDausach <<  " dau sach : \n";
        for (int i = 0; i < soluongDausach; i++)
        {
            listDausach[i]->Xuat();
        }
        
    }

};