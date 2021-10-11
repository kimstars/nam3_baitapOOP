#include "nguoi.h"

class Nhanvien : public Nguoi
{
    private:
        int luong;
    public : 
        void Nhap(){
            Nguoi::Nhap();
            cout <<"Nhap luong : ";
            cin >> luong;
        }

        void Xuat(){
            Nguoi::Xuat();
            cout << ",Luong " << luong << endl;
        }

        int getluong(){
            return luong;
        }
};