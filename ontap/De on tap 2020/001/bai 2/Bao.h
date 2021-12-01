#include "Book.h"


class Bao: public Book {
private:
    int ngayphathanh;
public:


    void Nhap(){
        cout << "Nhap BAO : ";
        Book::Nhap();
        
        cout << "Nhap thang phat hanh tap chi " << name << " : ";
        cin >> ngayphathanh;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap thang phat hanh tap chi " << name << " : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> ngayphathanh;
        }
    }

    void Xuat(){
        cout << "BAO : ";
        Book::Xuat();
        cout << "Ngay phat hanh :" <<setw(10)<< ngayphathanh << endl;
    }

    bool CheckType(int type)
    {
        if (type == 3)
            return true;
        return false;
    }
    

};