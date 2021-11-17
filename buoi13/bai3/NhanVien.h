#include "Nguoi.h"

class NhanVien : public Nguoi

{
private:
    float tienluong;
    float hesoluong;
    float phucap;
    string phongban;

public:
    ~NhanVien(){};
    NhanVien()
    {
        tienluong = 0;
        hesoluong = 0;
        phucap = 0;
        phongban = "NULL";
    };
    void operator=(NhanVien a)
    {
        name = a.getName();
        namsinh = a.getNamsinh();
        quequan = a.getQueQuan();
        hesoluong = a.getHesoluong();
        phucap = a.getPhucap();
        phongban = a.getPhongban();
        tinhtuoi();
        Tinhluong();

    }

    NhanVien(string name, int namsinh, string quequan, float hesoluong, float phucap, string phongban) : Nguoi(name, namsinh, quequan)
    {
        this->hesoluong = hesoluong;
        this->phucap = phucap;
        this->phongban = phongban;
    }
    void Nhap()
    {
        Nguoi::Nhap();
        cout << "\nNhap  he so luong: ";
        cin >> hesoluong;
        cout << "\nNhap phu cap: ";
        cin >> phucap;
        cout << name << " thuoc phong ban:";
        fflush(stdin);
        getline(cin, phongban);
        Tinhluong();
    }
    void Tinhluong()
    {
        tienluong = hesoluong * 1300 + phucap;
    }
    void Xuat()
    {
        Nguoi::Xuat();
        cout << "| Tien Luong : " << setw(20) << tienluong;
        cout << "| Phong ban : " << setw(10) << phongban << endl;
    }
    float getTienluong()
    {
        return tienluong;
    }

    string getDepartment()
    {
        return phongban;
    }
    float getHesoluong(){
        return hesoluong;
    }

    float getPhucap(){
        return phucap;
    }
    string getPhongban(){
        return phongban;
    }

    bool operator<(const NhanVien &a) const
    {
        return tienluong < a.tienluong;
    }
    bool checkName(string yourname)
    {
        if (yourname == name)
        {
            return 1;
        }
        return 0;
    }
    bool checkPhongban(string yourname)
    {
        if (yourname == phongban)
        {
            return 1;
        }
        return 0;
    }
};
