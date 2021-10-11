#include "dausach.h"

class Quanlysach : public dausach
{
private:
    vector<dausach *> listDausach;
    vector<Book *> listBook;
    int soLuongDausach;
    int soLuongSach;

public:
    Quanlysach()
    {
        listDausach.resize(0);
        listBook.resize(0);
        soLuongDausach = soLuongSach = 0;
    }

    void NhapDausach()
    {
        cout << "NHAP TEN DAU SACH------------------------- \n";
        cout << "So luong dau sach muon nhap : ";
        cin >> soLuongDausach;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "So luong dau sach muon nhap : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> soLuongDausach;
        }
        cout << "Nhap " << soLuongDausach << " dau sach : \n";
        for (int i = 0; i < soLuongDausach; i++)
        {
            listDausach.push_back(new dausach());
            listDausach[listDausach.size() - 1]->Nhap();
        }
    }
    void NhapSach()
    {
        string tenDausach;
        // XuatTenDausach();
        cout << "Nhap ten DAU SACH muon nhap : ";
        fflush(stdin);
        getline(cin, tenDausach);
        for (int i = 0; i < soLuongDausach; i++)
        {
            if (tenDausach == listDausach[i]->getName())
            {
                listBook.push_back(new Book());
                listBook[listBook.size() - 1]->Nhap();
                listBook[listBook.size() - 1]->setType(tenDausach);
                break;
            }
        }
        soLuongDausach = listDausach.size();
    }

    void XuatTheoDausach()
    {
        cout << "XUAT THEO DAU SACH \n";
        string tenDausach;
        // XuatTenDausach();
        cout << "Nhap ten DAU SACH muon show : ";
        fflush(stdin);
        getline(cin, tenDausach);
        int check = 0;
        cout << "++++++++++++++++++++++++++++\n";
        for (int i = 0; i < soLuongDausach; i++)
        {
            if (tenDausach == listDausach[i]->getName())
            {
                break;
            }
            ++check;
        }

        if (check < soLuongDausach)
        {
            for (int j = 0; j < listBook.size(); j++)
            {
                if (listBook[j]->getType() == tenDausach)
                {
                    listBook[j]->Xuat();
                }
            }
        }
        else
        {
            cout << "Khong co ten dau sach nay !! Kiem tra lai \n";
        }
        cout << "++++++++++++++++++++++++++++\n";
    }

    void XuatALL()
    {
        cout << "TONG SO SACH " << listBook.size() << endl;
        cout << "So luong dau sach  : ";
        cout << soLuongDausach << endl;
        cout << "DANH SACH TAT CA SACH \n";
        cout << "++++++++++++++++++++++++++++\n";
        for (int i = 0; i < listBook.size(); i++)
        {
            listBook[i]->Xuat();
        }
        cout << "++++++++++++++++++++++++++++\n";
    }

    void XuatTenDausach()
    {
        for (int i = 0; i < listDausach.size(); i++)
        {
            cout << i << " : " << listDausach[i]->getName() << endl;
        }
    }

    void Bansach()
    {
        string name;
        cout << "Nhap ten sach muon ban : ";
        cin >> name;
        int check = 0;
        int i = 0;
        for (; i < listBook.size(); i++)
        {
            if (name == listBook[i]->getName())
            {
                break;
            }
            ++check;

            /* code */
        }
        if (check < listBook.size())
        {
            listBook.erase(listBook.begin() + i);
        }
        soLuongSach = listBook.size();
    }

    void Menu()
    {
        cout << "++++++++++++++++++++++++++++\n";
        int CatchKey;
        do
        {
            cout << "\n________________________________________________________\n";
            cout << "Quan ly : \n";
            cout << "\t Press 1. Nhap dau sach.\n";
            cout << "\t Press 2. Nhap sach.\n";
            cout << "\t______________________________\n";
            cout << "\t Press 3. Show ALL.\n";
            cout << "\t Press 4. Show ten dau sach.\n";
            cout << "\t Press 5. Show 'danh sach' theo 'dau sach'.\n";
            cout << "\t______________________________\n";
            cout << "\t Press 6. Ban mot quyen sach.\n";

            cout << "\t Press 0. Exit.\n";
            cout << "\n________________________________________________________\n";
            cout << "Press:";

            while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6 && CatchKey != 0)
            {
                cout << "\nNO FEATURE!\nAgain: ";
            }

            switch (CatchKey)
            {
            case 1:
                NhapDausach();

                pressAnyKey();
                break;

            case 2:
                NhapSach();
                pressAnyKey();
                break;

            case 3:
                XuatALL();
                pressAnyKey();
                break;
            case 4:
                XuatTenDausach();
                pressAnyKey();
                break;
            case 5:
                XuatTheoDausach();
                pressAnyKey();
                break;
            case 6:
                Bansach();
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