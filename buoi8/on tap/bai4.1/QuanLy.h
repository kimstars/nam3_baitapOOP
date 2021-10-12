#include "Nhanvien.h"

class QuanLy
{
    vector<NhanVien *> nv;
    int n;

public:
    QuanLy(int n)
    {
        this->n = n;
        nv.resize(0);
    }
    QuanLy()
    {
        n = 0;
        nv.resize(0);
    };

    void Nhap()
    {
        cout << "Nhap so nhan vien : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\n______________________\n";
            cout << "Nhap nhan vien thu " << i+1 << ":" << endl;
            nv.push_back(new NhanVien());
            nv[nv.size() - 1]->Nhap();
        }
    }
    void Xuat()
    {

        for (int i = 0; i < nv.size(); i++)
        {
            // cout << nv[i]->getNamsinh();
            nv[i]->Xuat();
            cout << endl;
        }
    }
    static bool cmpTuoi(NhanVien *a, NhanVien *b)
    {
        return (*a).getTuoi() < (*b).getTuoi();
    }

    static bool cmpLuong(NhanVien *a, NhanVien *b)
    {
        return (*a).getTienluong() > (*b).getTienluong() ;
    }



    // void getName(NhanVien *a){
    //     cout <<"Ten cua nhan vien la: " << (*a).getTuoi() << endl;
    // }
    // void show(){
    //     getName(nv[0]);
    // }

    void SapXepTuoi()
    {
        sort(nv.begin(), nv.end(), cmpTuoi);
    }

    void SapXepLuong()
    {
        sort(nv.begin(), nv.end(), cmpLuong);
    }

    void FindBestSalary(){
        int luong = 0,id = 0;
        for (int  i = 0; i < nv.size() ; i++)
        {
            if(nv[i]->getTienluong() > luong)
            {
                luong = nv[i]->getTienluong();
                id = i;
            }
            /* code */
        }
        cout << "Nhan vien co luong cao nhat la : \n";
        nv[id]->Xuat();

        

    }
void Menu()
    {
        cout << "++++++++++++++++++++++++++++ CHU_TUAN_KIET ++++++++++++++++++++++++++++\n";
        int CatchKey;
        do
        {
            cout << "\t\t\tQUAN LY NHAN VIEN\n";
            cout << "\n\t________________________________________________________\n";
            cout << "\t Press 1. Nhap danh sach nhan vien.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 2. Sap xep danh sach theo tien luong giam dan .\n";
            cout << "\t Press 3. Sap xep danh sach theo tuoi tang dan.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 4. Show danh sach nhan vien.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 5. Nhan vien co luong cao nhat !!.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 0. Exit.\n";
            cout << "\n\t________________________________________________________\n";
            cout << "Press:";

            while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6 && CatchKey != 0)
            {
                cout << "\nNO FEATURE!\nAgain: ";
            }

            switch (CatchKey)
            {
            case 1:
                Nhap();
                SapXepLuong();
                pressAnyKey();
                break;

            case 2: // sap xep tien luong giam dan
                cout << "\tSap xep danh sach theo tien luong giam dan .\n";
                SapXepLuong();
                Xuat();
                pressAnyKey();
                break;

            case 3:
                cout << "Sap xep danh sach theo tuoi tang dan.\n";
                SapXepTuoi();
                Xuat();
                pressAnyKey();
                break;
            case 4:
                Xuat();
                pressAnyKey();
                break;
            case 5:
                FindBestSalary();
                pressAnyKey();
                break;
            default:
                break;
            }
        } while (CatchKey != 0);
        cout << "Thanks!";
    }

    void pressAnyKey()
    {
        system("pause");
        system("cls");
    }
};