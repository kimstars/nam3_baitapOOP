#include "Hopdong.h"
#include "Bienche.h"

class DanhSachNhanSu
{
private:
    int n;
    vector<NhanSu *> Nhanvien;

public:
    DanhSachNhanSu();
    void themNhansu();
    void themNhieuNhansu();
    void themHopDong();
    void themBienChe();
    void TimKiemtheoID();
    void SoluongNhansuBienche();
    void QuanLy();
    void Show();
    void pressAnyKey()
    {
        system("pause");
        system("cls");
    }
};
DanhSachNhanSu::DanhSachNhanSu()
{
    n = 0;
    Nhanvien.resize(0);
};

void DanhSachNhanSu::themNhansu()
{
    cout << "Chon loai nhan vien: \n";
    cout << "1. Nhan vien hop dong.\n";
    cout << "2. Nhan vien bien che.\n";
    int c;
    cin >> c;
    switch(c)
    {
    case 1:
        themHopDong();
        break;
    case 2:
        themBienChe();
        break;
    default:
        break;
    }
    n++;
}

void DanhSachNhanSu::themNhieuNhansu()
{
    int soluong;
    cout << "Nhap so luong nhan su can them : ";
    cin >> soluong;
    while (cin.fail())
    {
        cout << "Vui long nhap so tu nhien. \n";
        cout << "Nhap so luong nhan su can them : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> soluong;
    }
    for (int i = 0; i < soluong; i++)
    {
        themNhansu();
    }
    
}

void DanhSachNhanSu::themHopDong()
{
    Nhanvien.push_back(new HopDong());
    Nhanvien[Nhanvien.size() - 1]->Nhap();
}
void DanhSachNhanSu::themBienChe()
{
    Nhanvien.push_back(new BienChe());
    Nhanvien[Nhanvien.size() - 1]->Nhap();
}

void DanhSachNhanSu::TimKiemtheoID()
{
    string id;
    cout << "Nhap ma nhan vien can tim kiem : ";
    cin >> id;
    for (int i = 0; i < Nhanvien.size(); i++)
    {
        if (id == Nhanvien[i]->getID())
        {
            Nhanvien[i]->Print();
            break;
        }
    }
}
void DanhSachNhanSu::SoluongNhansuBienche()
{
    int count = 0;
    for (int i = 0; i < Nhanvien.size(); i++)
    {
        BienChe *check = dynamic_cast<BienChe *>(Nhanvien[i]);
        if (check)
        {
            count++;
        }
    }
    cout << "Hien tai co " << count << " nhan su bien che !!\n";
}


void DanhSachNhanSu::Show(){
    cout << "DANH SACH NHAN SU TRONG NHA MAY \n";
    for (int i = 0; i < Nhanvien.size() ; i++)
    {
        Nhanvien[i]->Print();
        /* code */
    }
    
}

void DanhSachNhanSu::QuanLy()
{
    cout << "++++++++++++++++++++++++++++\n";
    int CatchKey;
    do
    {
        cout << "\n________________________________________________________\n";
        cout << "Quan ly : \n";
        cout << "\t Press 1. Them 1 nhan su moi.\n";
        cout << "\t Press 2. Them nhieu nhan su.\n";
        cout << "\t______________________________\n";
        cout << "\t Press 3. Tim kiem theo ma nhan su.\n";
        cout << "\t Press 4. Show list nhan su.\n";
        cout << "\t Press 5. So luong nhan su bien che.\n";
        cout << "\t______________________________\n";
        // cout << "\t Press 6. Tang luong cho Giao vien\n";

        cout << "\t Press 0. Exit.\n";
        cout << "Press:";

        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6 && CatchKey != 0)
        {
            cout << "\nNO FEATURE!\nAgain: ";
        }

        switch (CatchKey)
        {
        case 1:
            themNhansu();
            break;

        case 2:
            themNhieuNhansu();
            pressAnyKey();
            break;

        case 3:
            TimKiemtheoID();
            pressAnyKey();
            break;
        case 4:
            Show();
            pressAnyKey();
            break;
        case 5:
            SoluongNhansuBienche();
            pressAnyKey();
            break;
        
        default:
            break;
        }
    } while (CatchKey != 0);
    cout << "Thanks!";
}
