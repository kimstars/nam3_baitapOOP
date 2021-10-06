// 4.	Xây dựng lớp người Nguoi gồm: họ tên, ngày tháng năm sinh, quê quán và các phương thức: nhập, in ra. Các toán tử so sánh theo tuổi.
// Xây dựng lớp nhân viên Nhanvien thừa kế từ lớp trên và có thêm: tiền lương, chức vụ. Và có các phương thức: nhập, in ra. Các toán tử  so sánh tiền lương của 2 nhân viên.
// Lập chương trình chính gồm các chức năng:
// •	Nhập danh sách N (N<=20) nhân viên - Sắp xếp danh sách nhân viên theo thứ tự giảm của tiền lương
// •	In ra danh sách nhân viên gồm: Họ tên, năm sinh, tên môn thi, tiền lương, chức vụ
// •	Sắp xếp nhân viên theo thứ tự tăng dần của tuổi
// •	Sắp xếp nhân viên theo thứ tự tăng dần của lương.
// Tìm và in ra các nhân viên có tiền lương cao nhất
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Nguoi
{
protected:
    string name;
    string ngaysinh;
    string quequan;
    int tuoi;

public:
    Nguoi() {};
    Nguoi(string name, string ngaysinh, string quequan, int tuoi)
    {
        this->name = name;
        this->ngaysinh = ngaysinh;
        this->quequan = quequan;
        this->tuoi = tuoi;
    }
    virtual void Nhap()
    {
        fflush(stdin);
        cout << "\nHay Nhap Ten: ";
        getline(cin, name);
        fflush(stdin);
        cout << "\nHay Nhap Ngay Sinh: ";
        getline(cin, ngaysinh);
        fflush(stdin);
        cout << "\nHay Nhap Que Quan: ";
        getline(cin, quequan);
        fflush(stdin);
        cout << "\nHay Nhap Tuoi: ";
        cin >> tuoi;
    }
    void Xuat()
    {
        cout << "\nTen la: " << name;
        cout << "\nNgay Thang Nam Sinh: " << ngaysinh;
        cout << "\nDia Chi Thuong Tru: " << quequan;
        cout << "\nTuoi La: " << tuoi;
    }
    int operator>(Nguoi n)
    {
        Nguoi m;
        if (m.tuoi > n.tuoi)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int operator<(Nguoi n)
    {
        Nguoi m;
        if (m.tuoi < n.tuoi)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }
    int operator=(Nguoi n)
    {
        Nguoi m;
        if (m.tuoi == n.tuoi)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int getTuoi()
    {
        return tuoi;
    }
    string getNgaysinh()
    {
        return ngaysinh;
    }
    string getName()
    {
        return name;
    }
    string getQueQuan()
    {
        return quequan;
    }
};

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
};

class Quanli
{
    NhanVien *NV;
    int n;

public:
    Quanli(int n)
    {
        this->n = n;
    }
    Quanli(NhanVien *NV)
    {
        for (int i = 0; i < sizeof(NV); i++)
        {
            this->NV = NV;
        }
    }

    void Nhap()
    {
        NV = new NhanVien[n];
        for (int i = 0; i < n; i++)
        {
            NV[i].Nhap();
        }
    }
    void Xuat()
    {

        for (int i = 0; i < n; i++)
        {
            NV[i].Xuat();
            cout << endl;
        }
    }
    void SapXepLL()
    {

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (NV[i].getTienluong() > NV[j].getTienluong())
                {
                    swap(NV[i], NV[j]);
                }
            }
        }
    }
    void SapXepT()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (NV[i].getTuoi() < NV[j].getTuoi())
                {
                    swap(NV[i], NV[j]);
                }
            }
        }
    }

    void SapXepLB()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (NV[i].getTienluong() < NV[j].getTienluong())
                {
                    swap(NV[i], NV[j]);
                }
            }
        }
    }
    void TimKiem()
    {
        float max = NV[0].getTienluong();
        for (int i = 0; i < n; i++)
        {
            if (NV[i].getTienluong() > max)
                max = NV[i].getTienluong();
        }

        for (int i = 0; i < n; i++)
        {
            if (NV[i].getTienluong() == max)
                NV[i].Xuat();
        }
    }
};


int main()
{
    Quanli QL(2);
    QL.Nhap();
    QL.SapXepLB();
    cout << "\n Danh sach sap xep theo tien luong giam dan: ";
    QL.Xuat();
    //     QL.SapXepLL();
    //     cout<<"\nDanh sach sap xep theo tien luong tang dan: ";
    //     QL.Xuat();
    //     QL.SapXepT();
    //     cout<<"\nDanh Sach sap xep theo tuoi: ";
    //     QL.Xuat();
    //     cout<<"\nNguoi co Muc Luong Cao nhat: ";
    //     QL.TimKiem();
    //
}
