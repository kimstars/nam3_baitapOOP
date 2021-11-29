
#include "vang.h"
#include "tiente.h"

#include <fstream>

class QuanLy
{
    vector<GiaoDich *> GD;
    int n;

public:
    QuanLy(int n)
    {
        this->n = n;
        GD.resize(0);
    }
    QuanLy()
    {
        n = 0;
        GD.resize(0);
    };

    void Nhap(vector<GiaoDich *> &GD)
    {
        cout << "Nhap so giao dich : ";
        cin >> n;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap so luong giao dich can them : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> n;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "\n______________________\n";
            cout << "Nhap giao dich thu " << i + 1 << ":" << endl;
            themGiaodich(GD);
        }
    }
    void Xuat()
    {

        for (int i = 0; i < GD.size(); i++)
        {

            GD[i]->Xuat();
            cout << endl;
        }
    }

    void themGiaodich(vector<GiaoDich *> &GD)
    {
        cout << "Chon loai Giao dich: \n";
        cout << "1. Giao dich vang.\n";
        cout << "2. Giao dich tien te.\n";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            themGDVang(GD);
            break;
        case 2:
            themGDTiente(GD);
            break;
        default:
            break;
        }
        n++;
    }

    void themGDVang(vector<GiaoDich *> &GD)
    {
        GD.push_back(new GiaoDichVang);
        GD[GD.size() - 1]->Nhap();
    }
    void themGDTiente(vector<GiaoDich *> &GD)
    {
        GD.push_back(new GiaoDichTienTe);
        GD[GD.size() - 1]->Nhap();
    }

    void Menu()
    {
        cout << "++++++++++++++++++++++++++++ CHU_TUAN_KIET ++++++++++++++++++++++++++++\n";
        int CatchKey;
        do
        {
            cout << "\t\t\tQUAN LY Giao dich\n";
            cout << "\n\t________________________________________________________\n";
            cout << "\t Press 1. Nhap danh sach giao dich.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 2. Show danh sach giao dich.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 3. Tinh trung binh ty gia tat ca giao dich !!.\n";
            cout << "\t Press 4. Tim kiem giao dich theo ma giao dich !!.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 5. SUA thong tin giao dich theo ma giao dich.\n";
            cout << "\t Press 6. XOA thong tin giao dich theo ma giao dich.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 7. Ghi File\n";
            cout << "\t Press 8. Doc File\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 0. Exit.\n";
            cout << "\n\t________________________________________________________\n";
            cout << "Press:";

            while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6 && CatchKey != 7 && CatchKey != 8 && CatchKey != 9 && CatchKey != 10 && CatchKey != 11 && CatchKey != 0)
            {
                cout << "\nNO FEATURE!\nAgain: ";
            }

            switch (CatchKey)
            {
            case 1:
                Nhap(GD);
                pressAnyKey();
                break;

            case 2:
                Xuat();
                pressAnyKey();
                break;

            case 3:
                TBTtrigia();
                pressAnyKey();
                break;

            case 4:
                FindByID();
                pressAnyKey();
                break;

            case 5:
                EditByID(GD);
                pressAnyKey();
                break;
            case 6:
                DelByID(GD);
                pressAnyKey();
                break;
            case 7:
                writeFile(GD);
                pressAnyKey();
                break;
            case 8:
                readFile(GD);
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

    void TBTtrigia()
    {
        int sum = 0, count = 0;
        double res;
        for (int i = 0; i < GD.size(); i++)
        {
            sum += GD[i]->getTriGia();
            count++;
        }

        if (count)
        {
            cout << "Danh sach nay co " << count << "nguoi\n";
            cout << "Trung binh tri gia : " << sum / GD.size() << endl;
        }
        else
        {
            cout << "Khong co GD" << endl;
        }
    }

    void FindByID()
    {
        int count = 0;
        string ID;
        cout << "Nhap ten phong ban can tim kiem: ";
        fflush(stdin);
        getline(cin, ID);
        for (int i = 0; i < GD.size(); i++)
        {
            if (GD[i]->getMaGiaoDich() == ID)
            {
                GD[i]->Xuat();
                count++;
            }
        }
        if (count)
        {
            cout << "Danh sach nay co " << count << " nguoi\n";
        }
        else
        {
            cout << "Khong tim thay GD trong phong ban" << ID << endl;
        }
    }

    void EditByID(vector<GiaoDich *> &GD)
    {
        int count = 0;
        string ID;
        cout << "Nhap ten giao dich can sua: ";
        fflush(stdin);
        getline(cin, ID);
        for (int i = 0; i < GD.size(); i++)
        {
            if (GD[i]->getMaGiaoDich() == ID)
            {
                cout << "Sua thong tin giao dich " << ID;
                GD[i]->Nhap();
                count++;
                break;
            }
        }
        if (!count)
        {
            cout << "Khong tim thay GD" << ID << endl;
        }
    }
    void DelByID(vector<GiaoDich *> &GD)
    {
        int count = 0;
        string ID;
        cout << "Nhap ma giao dich can xoa: ";
        fflush(stdin);
        getline(cin, ID);
        for (vector<GiaoDich *>::iterator i = GD.begin(); i != GD.end(); i++)
        {
            if ((*i)->getMaGiaoDich() == ID)
            {
                char c;
                cout << "Da tim thay giao dich " << ID << "\nXac nhan xoa GD (y/n) : ";
                cin >> c;
                if (c == 'y')
                {
                    GD.erase(i);
                    cout << "Xoa giao dich thanh cong\n";
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
            cout << "Khong tim thay GD" << ID << endl;
        }
    }

    void writeFile(vector<GiaoDich *> &GD)
    {
        ofstream fout;
        fout.open("out.bin", ios::out | ios::binary);
        if (fout.good())
        {
            for (int i = 0; i < n; i++)
            {
                fout.write((char *)(&GD[i]), sizeof(GD[i]));
            }
        }
        fout.close();
        cout << "\nWrite successful !\n";
    }

    void readFile(vector<GiaoDich *> &GD)
    {
        // fstream fin;
        // fin.open("out.bin", ios::in | ios::binary);
        // int count = 0;
        // if (fin.good())
        // {
        //     fin.seekg(0, ios::beg);
        //     while (!fin.eof())
        //     {
        //         GiaoDich a;
        //         if (fin.read(reinterpret_cast<char *>(&a), sizeof(a)))
        //         {
        //             a.Xuat();
        //             GD.push_back(&a);
        //             count++;
        //         }
        //     }
        //     n = count;
        //     cout << "\nRead successful !\n";
        // }
        // else
        // {
        //     cout << "error open file \n";
        // }
        // fin.close();
    }
};