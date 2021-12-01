#include "Book.h"


class Tapchi: public Book {
private:
    int sophathanh;
    int thangphathanh;
public:


    void Nhap(){
        cout << "Nhap TAP CHI : ";
        Book::Nhap();
        cout << "Nhap so phat hanh : ";
        cin >> sophathanh;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap so phat hanh '" << name << "' : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> sophathanh;
        }
        cout << "Nhap thang phat hanh tap chi '" << name << "' : ";
        cin >> thangphathanh;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap thang phat hanh tap chi '" << name << "' : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> thangphathanh;
        }

    }

    void Xuat(){
        cout << "TAP CHI : ";
        Book::Xuat();
        cout << "So phat hanh : " <<left <<setw(10)<< sophathanh << " | ";
        cout << "Thanh phat hanh :" <<setw(10)<< thangphathanh << endl;
    }

    bool CheckType(int type)
    {
        if (type == 2)
            return true;
        return false;
    }
    

};