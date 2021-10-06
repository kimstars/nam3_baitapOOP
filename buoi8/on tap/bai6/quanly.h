#include "dausach.h"

class Quanlysach : public dausach
{
private:
    vector<dausach *> listDausach;
    int soLuongDausach;
    int soLuongSach;

public:
    Quanlysach()
    {
        listDausach.resize(0);
        soLuongDausach = soLuongSach = 0;
    }

    void NhapDausach()
    {
        cout << "NHAP TEN DAU SACH------------------------- \n";
        cout << "So luong dau sach muon nhap : ";
        cin >> soLuongDausach;
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
        cout << "Nhap ten dau sach muon nhap : ";
        cin >> tenDausach;
        for (int i = 0; i < soLuongDausach; i++)
        {
            if(tenDausach == listDausach[i]->getName()){
                listDausach[i]->addBook();
                soLuongSach += listDausach[i]->getSizeList();
                break;
            }
        }
    }

    void XuatALL()
    {
        cout << "TONG SO SACH "  << soLuongSach << endl;
        cout << "So luong dau sach  : ";
        cout << soLuongDausach << endl ;
        for (int i = 0; i < soLuongDausach; i++)
        {
            cout << "++++++++++++++++++++++++++++\n";
            listDausach[i]->Xuat();
            cout << endl;
            cout << "++++++++++++++++++++++++++++\n";

        }
    }

    void XuatTenDausach(){
        for (int i = 0; i < soLuongDausach; i++)
        {
            cout << i << " : "<< listDausach[i]->getName() << endl;
        }

    }

    void Bansach(){
        string name;
        cout << "Nhap ten sach muon ban : ";
        cin >> tenDausach;
        
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
            cout << "\t Press 4. Show danh sach dau sach.\n";
            cout << "\t______________________________\n";
            cout << "\t Press 5. Ban mot quyen sach.\n";


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