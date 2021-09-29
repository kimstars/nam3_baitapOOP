#include "sinhvien.h"
#include "giaovien.h"


void NhapGV(vector<Nguoi *> &p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap giao vien thu " << i + 1 << " : \n";
        p.push_back(new GV());
        p[p.size() -1]->Nhap();
    }
    cout << endl;
}

void NhapSV(vector<Nguoi *> &p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap sinh vien thu " << i + 1 << " : \n";
        p.push_back(new SV());
        p[p.size() -1]->Nhap();
    }
}

void showGV(vector<Nguoi *> &p)
{
    cout << endl;
    int index = 0;
    for (int i = 0; i < p.size(); i++)
    {
        cout << "_____________________________\n";
        GV *check = dynamic_cast<GV *>(p[i]);
        if (check)
        {
            cout << "Thong tin giao vien thu  " << ++index << endl;
            check->Xuat();
        }else{
            continue;
        }
        cout << "_____________________________\n";
    }
}

void showSV(vector<Nguoi *> &p)
{
    cout << endl;
    int index = 0;
    for (int i = 0; i < p.size(); i++)
    {
        cout << "_____________________________\n";
        SV *check = dynamic_cast<SV *>(p[i]);
        if (check){
            cout << "Thong tin sinh vien thu  " << ++index << endl;
            check->Xuat();
        }else{
            continue;
        }
        cout << "_____________________________\n";
    }
}

void showALL(vector<Nguoi *> &p)
{
    cout << endl;
    for (int i = 0; i < p.size(); i++)
    {
        cout << "_____________________________\n";
        cout << "Thong tin thu  " << i + 1 << endl;
        p[i]->Xuat();
        cout << "_____________________________\n";
    }
}

void tangluong(vector<Nguoi *> &p){
    cout << endl;
    string name;
    cout << "Nhap Ho va ten GV can ++luong : ";
    fflush(stdin);
    getline(cin,name);
    int index=0;
    for (int i = 0; i < p.size(); i++)
    {
        index++;
        if(p[i]->getName() == name){
            GV *check = dynamic_cast<GV *>(p[i]);
            check->tangluong();
            cout << "Tang luong thanh cong !!\n";
            return;
        }
    }
    if(index == p.size()){
        cout << "khong tim thay GV\n";
        cout << "Ban can viet dung in hoa (vd : Chu Tuan Kiet)\n";
    }
}

void pressAnyKey()
{
    system("pause");
    system("cls");
}

int main()
{
    vector<Nguoi *> p;

    int n, m;
    cout << "++++++++++++++++++++++++++++\n";
    int CatchKey;
    do
    {
        cout << "\n________________________________________________________\n";
        cout << "Quan ly : \n";
        cout << "\t Press 1. Them Giao vien.\n";
        cout << "\t Press 2. Them Sinh vien.\n";
        cout << "\t______________________________\n";
        cout << "\t Press 3. Show list Giao vien.\n";
        cout << "\t Press 4. Show list Sinh vien.\n";
        cout << "\t Press 5. Show ALL.\n";
        cout << "\t______________________________\n";
        cout << "\t Press 6. Tang luong cho Giao vien\n";
        

        cout << "\t Press 0. Exit.\n";
        cout << "Press:";

        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 
        && CatchKey != 5&& CatchKey != 6 && CatchKey != 0)
        {
            cout << "\nNO FEATURE!\nAgain: ";
        }

        switch (CatchKey)
        {
        case 1:
            cout << "Nhap so giao vien : ";
            cin >> n;
            while (cin.fail())
            {
                cout << "Vui long nhap so tu nhien. \n";
                cout << "Nhap so giao vien : ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> n;
            }
            NhapGV(p, n);
            pressAnyKey();
            break;

        case 2:
            cout << "Nhap so sinh vien : ";
            cin >> m;
            while (cin.fail())
            {
                cout << "Vui long nhap so tu nhien. \n";
                cout << "Nhap so sinh vien : ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> m;
            }
            NhapSV(p, m);
            pressAnyKey();
            break;
        
        case 3:
            cout << "Thong tin giao vien : ";
            showGV(p);
            pressAnyKey();
            break;
        case 4:
            cout << "Thong tin sinh vien : ";
            showSV(p);
            pressAnyKey();
            break;
        case 5:
            cout << "Thong tin SV GV : ";
            showALL(p);
            pressAnyKey();
            break;
        case 6:
            tangluong(p);            
            pressAnyKey();
            break;
        default:
            break;
        }
    } while (CatchKey != 0);
    cout << "Thanks!";
}
