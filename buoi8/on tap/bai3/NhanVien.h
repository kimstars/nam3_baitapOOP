#include "Nguoi.h"

class NhanVien : public Nguoi
{
private:
    float tienluong;
    string chucvu;

public:
    NhanVien() {}
    NhanVien(string name, string ngaysinh, string quequan, int tuoi, float tienluong, string chucvu) : Nguoi(name, ngaysinh, quequan, tuoi)
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
        cout << "\nChuc Vu Cua Nhan Vien la: " << chucvu;
    }
    float getTienluong()
    {
        return tienluong;
    }

    void swap(NhanVien &p){
        NhanVien temp(p.name, p.ngaysinh, p.quequan, p.tuoi, p.tienluong, p.chucvu);

        p.name= this->name;
        p.ngaysinh = this->ngaysinh;
        p.quequan = this->quequan;
        p.tuoi = this->tuoi;
        p.tienluong = this->tienluong;
        p.chucvu = this->chucvu;

        this->name= temp.name;
        this->ngaysinh = temp.ngaysinh;
        this->quequan = temp.quequan;
        this->tuoi = temp.tuoi;
        this->tienluong = temp.tienluong;
        this->chucvu = temp.chucvu;
    }
};
