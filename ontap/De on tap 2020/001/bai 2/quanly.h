#include "Sach.h"
#include "Tapchi.h"
#include "Bao.h"

class QuanLy
{
private:
    vector<Book *> B;
    int n;

public:
    void Nhap(vector<Book *> &B)
    {
        cout << "Nhap so sach : ";
        cin >> n;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cout << "Nhap so luong sach can them : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> n;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "\n______________________\n";
            cout << "Nhap sach thu " << i + 1 << ":" << endl;
            addBook(B);
        }
    }

    void addBook(vector<Book *> &B)
    {
        cout << "Chon loai : \n";
        cout << "1. THEM SACH.\n";
        cout << "2. THEM TAP CHI.\n";
        cout << "3. THEM BAO.\n";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            themSach(B);
            break;
        case 2:
            themTapchi(B);
            break;
        case 3:
            themBao(B);
            break;
        default:
            break;
        }
    }

    void themSach(vector<Book *> &B)
    {
        B.push_back(new Sach());
        B[B.size() - 1]->Nhap();
    }
    void themTapchi(vector<Book *> &B)
    {
        B.push_back(new Tapchi());
        B[B.size() - 1]->Nhap();
    }
    void themBao(vector<Book *> &B)
    {
        B.push_back(new Bao());
        B[B.size() - 1]->Nhap();
    }

    void Xuat(vector<Book *> B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            B[i]->Xuat();
            cout << endl;
        }
    }

    void TimKiem()
    {
        cout << "Chon loai can tim kiem : ";
        cout << "Chon loai : \n";
        cout << "1.SACH.\n";
        cout << "2.TAP CHI.\n";
        cout << "3.BAO.\n";
        cout << "Chon : ";
        int type;
        cin >> type;
        while (cin.fail())
        {
            cout << "Vui long nhap so tu nhien. \n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> type;
        }


        string name;
        cout << "Nhap ten sach can tim :";
        fflush(stdin);
        getline(cin, name);


        for (int i = 0; i < B.size(); i++)
        {
            if (B[i]->CheckType(type) && B[i]->CheckName(name)){
                // cout << B[i]->CheckType(type) ;
                B[i]->Xuat();
                cout << endl;
            }
        }
    }


    void Menu()
    {
        cout << "++++++++++++++++++++++++++++ CHU_TUAN_KIET ++++++++++++++++++++++++++++\n";
        int CatchKey;
        do
        {
            cout << "\t\t\tQUAN LY SACH\n";
            cout << "\n\t________________________________________________________\n";
            cout << "\t Press 1. Nhap danh sach SACH.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 2. Show danh sach SACH.\n";
            cout << "\t________________________________________________________\n";
            cout << "\t Press 3. Tim kiem SACH theo ma SACH !!.\n";
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
                Nhap(B);
                pressAnyKey();
                break;

            case 2:
                Xuat(B);
                pressAnyKey();
                break;

            case 3:
                TimKiem();
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