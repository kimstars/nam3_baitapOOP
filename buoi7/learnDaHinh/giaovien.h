#include "nguoi.h"

class GV : public Nguoi
{
private:
    double base;
    double luong;

public:
    GV(){};
    ~GV();
    GV(string name, int birth, bool gender, double base, double luong) : Nguoi(name, birth, gender)
    {
        base = base;
        luong = luong;
    }

    void Nhap()
    {
        Nguoi::Nhap();

        cout << "Nhap hs luong : ";
        cin >> base;
        while (cin.fail())
        {
            cout << "Vui long nhap so thuc. \n";
            cout << "Nhap he so luong : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> base;
        }
        tinhluong();
    }
    void Xuat()
    {
        cout << "Thong tin giao vien : " << endl;
        Nguoi::Xuat();
        cout << "- hs luong : " << base << endl;
        cout << "- Luong hien tai : " << luong << endl;
    }

    void tinhluong()
    {
        luong = 1300 * base;
    }
    void tangluong()
    {
        cout << "Thay doi he so de tang luong : ";
        cin >> base;
        tinhluong();
    }
};