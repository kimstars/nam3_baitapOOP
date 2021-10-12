#include "Nguoi.h"

class NhanVien : public Nguoi

{
public:
    float tienluong;
    string chucvu;

public:
    NhanVien() {}
    NhanVien(string name, int ngaysinh, string quequan, float tienluong, string chucvu) : Nguoi(name, ngaysinh, quequan)
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
        cout <<", Tien Luong : "<<setw(20) << tienluong;
        cout << ", Chuc Vu : " <<setw(10)<< chucvu << endl;
    }
    float getTienluong()
    {
        return tienluong;
    }

    bool operator<(const NhanVien &a) const {
        return tienluong < a.tienluong;
    }

};
