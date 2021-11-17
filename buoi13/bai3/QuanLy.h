#include "Nhanvien.h"
#include <fstream>
class QuanLy
{
    vector<NhanVien> nv;
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

    void Nhap(vector<NhanVien> &nv)
    {
        cout << "Nhap so nhan vien : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\n______________________\n";
            cout << "Nhap nhan vien thu " << i + 1 << ":" << endl;
            NhanVien a;
            a.Nhap();
            nv.push_back(a);
        }
    }
    void Xuat()
    {

        for (int i = 0; i < nv.size(); i++)
        {
            // cout << nv[i].getNamsinh();
            nv[i].Xuat();
            cout << endl;
        }
    }
    static bool cmpTuoi(NhanVien a, NhanVien b)
    {
        return a.getTuoi() < b.getTuoi();
    }

    static bool cmpLuong(NhanVien a, NhanVien b)
    {
        return a.getTienluong() > b.getTienluong();
    }

    void SapXepTuoi(vector<NhanVien> &nv)
    {
        sort(nv.begin(), nv.end(), cmpTuoi);
    }

    void SapXepLuong(vector<NhanVien> &nv)
    {
        sort(nv.begin(), nv.end(), cmpLuong);
    }

    void FindBestSalary()
    {
        int luong = 0, id = 0;
        for (int i = 0; i < nv.size(); i++)
        {
            if (nv[i].getTienluong() > luong)
            {
                luong = nv[i].getTienluong();
                id = i;
            }
            /* code */
        }
        cout << "Nhan vien co luong cao nhat la : \n";
        nv[id].Xuat();
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
            cout << "\t Press 6. Tim kiem nhan vien theo ten NHAN VIEN !!.\n";
            cout << "\t Press 7. Tim kiem nhan vien theo ten PHONG BAN !!.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 8. SUA thong tin nhan vien theo ten NHAN VIEN.\n";
            cout << "\t Press 9. XOA thong tin nhan vien theo ten NHAN VIEN.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 10. Ghi File\n";
            cout << "\t Press 11. Doc File\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 0. Exit.\n";
            cout << "\n\t________________________________________________________\n";
            cout << "Press:";

            while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6 && CatchKey != 7 && CatchKey != 8 && CatchKey != 9&& CatchKey != 10&& CatchKey != 11 && CatchKey != 0)
            {
                cout << "\nNO FEATURE!\nAgain: ";
            }

            switch (CatchKey)
            {
            case 1:
                Nhap(nv);
                SapXepLuong(nv);
                pressAnyKey();
                break;

            case 2: // sap xep tien luong giam dan
                cout << "\tSap xep danh sach theo tien luong giam dan .\n";
                SapXepLuong(nv);
                Xuat();
                pressAnyKey();
                break;

            case 3:
                cout << "Sap xep danh sach theo tuoi tang dan.\n";
                SapXepTuoi(nv);
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
            case 6:
                FindbyName();
                pressAnyKey();
                break;
            case 7:
                FindbyDepartment();
                pressAnyKey();
                break;
            case 8:
                EditByName(nv);
                pressAnyKey();
                break;
            case 9:
                DelByName(nv);
                pressAnyKey();
                break;
            case 10:
                writeFile(nv);
                pressAnyKey();
                break;
            case 11:
                readFile(nv);
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

    void FindbyName()
    {
        int count = 0;
        string name;
        cout << "Nhap ten nhan vien can tim kiem: ";
        fflush(stdin);
        getline(cin, name);
        for (int i = 0; i < nv.size(); i++)
        {
            if (nv[i].checkName(name))
            {
                nv[i].Xuat();
            }
            count++;
        }
        if (count)
        {
            cout << "Danh sach nay co " << count << "nguoi\n";
        }
        else
        {
            cout << "Khong tim thay NV" << name << endl;
        }
    }

    void FindbyDepartment()
    {
        int count = 0;
        string name;
        cout << "Nhap ten phong ban can tim kiem: ";
        fflush(stdin);
        getline(cin, name);
        for (int i = 0; i < nv.size(); i++)
        {
            if (nv[i].checkPhongban(name))
            {
                nv[i].Xuat();
                count++;
            }
        }
        if (count)
        {
            cout << "Danh sach nay co " << count << " nguoi\n";
        }
        else
        {
            cout << "Khong tim thay NV trong phong ban" << name << endl;
        }
    }

    void EditByName(vector<NhanVien> &nv)
    {
        int count = 0;
        string name;
        cout << "Nhap ten nhan vien can sua: ";
        fflush(stdin);
        getline(cin, name);
        for (int i = 0; i < nv.size(); i++)
        {
            if (nv[i].checkName(name))
            {
                cout << "Sua thong tin nhan vien " << name;
                nv[i].Nhap();
                count++;
                break;
            }
        }
        if (!count)
        {
            cout << "Khong tim thay NV" << name << endl;
        }
    }
    void DelByName(vector<NhanVien> &nv)
    {
        int count = 0;
        string name;
        cout << "Nhap ten nhan vien can xoa: ";
        fflush(stdin);
        getline(cin, name);
        for (vector<NhanVien>::iterator i = nv.begin(); i != nv.end(); i++)
        {
            if ((*i).checkName(name))
            {
                char c;
                cout << "Da tim thay nhan vien " << name << "\nXac nhan xoa NV (y/n) : ";
                cin >> c;
                if (c == 'y')
                {
                    nv.erase(i);
                    cout << "Xoa nhan vien thanh cong\n";
                    count++;
                }
                else
                {
                    continue;
                }
                break;
            }
        }
        if (!count)
        {
            cout << "Khong tim thay NV" << name << endl;
        }
    }

    void writeFile(vector<NhanVien> &nv)
    {
        ofstream fout;
        fout.open("out.bin", ios::out | ios::binary);
        if (fout.good())
        {
            for (int i = 0; i < n; i++)
            {
                fout.write((char *)(&nv[i]), sizeof(nv[i]));
            }
        }
        fout.close();
        cout << "\nWrite successful !\n";
    }

    void readFile(vector<NhanVien> &nv)
    {
        fstream fin;
        fin.open("out.bin", ios::in | ios::binary);
        int count = 0;
        if (fin.good())
        {
            fin.seekg(0, ios::beg);
            while(!fin.eof()){
                NhanVien a;
                if(fin.read(reinterpret_cast<char*>(&a), sizeof(a))){
                    a.Xuat();
                    nv.push_back(a);
                    count++;
                }
            }
        n = count;
        cout << "\nRead successful !\n";
        }
        else
        {
            cout << "error open file \n";
        }
        fin.close();
    }
};