#include "Nguoi.h"

class NhanVien : public Nguoi

{
public:
    float tienluong;
    string chucvu;

public:
    NhanVien() {}
    NhanVien(string name, int namsinh, string quequan,float tienluong, string chucvu) : Nguoi(name, namsinh, quequan)
    {
        this->tienluong = tienluong;
        this->chucvu = chucvu;
    }
    void Nhap()
    {
        Nguoi::Nhap();
        fflush(stdin);
        cout << "\nHay Nhap tien luong: ";
        cin >> tienluong;
        fflush(stdin);
        cout << "\nHay Nhap Chuc Vu: ";
        getline(cin, chucvu);
    }
    void Xuat()
    {
        Nguoi::Xuat();
        cout << "\nTien Luong cua Nhan Vien la: " << tienluong;
        cout << "\nChuc Vu Cua Nhan Vien la: " << chucvu << endl;
    }
    float getTienluong()
    {
        return tienluong;
    }

    bool operator>(const NhanVien &a) const {
        return tienluong > a.tienluong;
    }


};
