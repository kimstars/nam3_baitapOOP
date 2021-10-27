#include "hocvien.h"

void pressAnyKey()
{
    system("pause");
    system("cls");
}

void NhapHV(vector<Hocvien> &p)
{
    int n;
    cout << "Nhap so hoc vien : ";
    cin >> n;
    while (cin.fail())
    {
        cout << "Vui long nhap so tu nhien. \n";
        cout << "Nhap so hoc vien : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap hoc vien thu " << i + 1 << " : \n";
        Hocvien hv;
        hv.Nhap();
        p.push_back(hv);
        // p[p.size() - 1].Nhap();
    }
    cout << endl;
}
int checkDiem(Hocvien p)
{
    if ((p).duoi5())
    {
        if ((p).getdiemtb() > 7)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 3;
    }
}

void ShowLuanVan(vector<Hocvien> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if ((p[i]).XepLoai() == 1)
        {
            cout << (p[i]);
        }
    }
}

void ShowALL(vector<Hocvien> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i];
    }
}

void ShowTotNghiep(vector<Hocvien> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if ((p[i]).XepLoai() == 2)
        {
            cout << (p[i]);
        }
    }
}

void ShowThiLai(vector<Hocvien> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if ((p[i]).XepLoai() == 3)
        {
            cout << (p[i]);
        }
    }
}

void HienthiDS(vector<Hocvien> &p)
{
    cout << "+++++++++++++++++++++++++++++\n";
    int CatchKey;
    do
    {
        cout << "\n________________________________________________________\n";
        cout << "Hien thi danh sach : \n";
        cout << "\t Press 1. Hoc vien duoc LAM LUAN VAN.\n";
        cout << "\t______________________________\n";
        cout << "\t Press 2. Hoc vien duoc THI TOT NGHIEP.\n";
        cout << "\t______________________________\n";
        cout << "\t Press 3. Hoc vien THI LAI\n";
        cout << "\t______________________________\n";
        cout << "\t Press 0. Exit.\n";
        cout << "Press:";

        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 0)
        {
            cout << "\nNO FEATURE!\nAgain: ";
        }

        switch (CatchKey)
        {
        case 1:

            ShowLuanVan(p);
            pressAnyKey();
            break;

        case 2:

            ShowTotNghiep(p);
            pressAnyKey();
            break;

        case 3:
            ShowThiLai(p);
            pressAnyKey();
            break;

        default:
            break;
        }
    } while (CatchKey != 0);
    cout << "Thanks!";
}

void SuaThongTin(vector<Hocvien> &p)
{
    cout << "Nhap chinh xac ten hoc vien can sua : ";
    fflush(stdin);
    string name;
    getline(cin, name);
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].getName() == name)
        {
            cout << "Tim thay hoc vien\n";
            cin >> (p[i]);
            return;
        }
    }
    cout << "Khong tim thay \n";
}

void GhiFile(vector<Hocvien> p)
{
    ofstream file;
    char str[10];
    file.open("output.bin", ios::out | ios::binary);
    if (!file)
    {
        cout << "Error in creating file...\n";
        return;
    }
    int n = p.size();
    file.write((char *)(&n), sizeof(n));

    for (int i = 0; i < n; i++)
    {
        Hocvien a = p[i];
        file.write((const char *)&(a), sizeof(Hocvien));
    }
    cout << "Ghi file thanh cong!!\n";
    file.close();
}

void DocFile(vector<Hocvien> &ds)
{
    ifstream file;
    file.open("output.bin", ios::in | ios::binary);
    char str[10];
    if (!file)
    {
        cout << "Error in file opening..." << endl;
        return;
    }
    int n = 0;

    // cout << n <<endl;
    file.read((char *)(&n), sizeof(n));
    while (n)
    {
        Hocvien hv;
        if (file.read((char *)&hv, sizeof(hv)))
        {
            ds.push_back(hv);
            n--;
        }
    }
    file.close();
}

int main()
{
    vector<Hocvien> p;

    cout << "++++++++++++++++++++++++++++\n";
    int CatchKey;
    do
    {
        cout << "\n________________________________________________________\n";
        cout << "Quan ly : \n";
        cout << "\t Press 1. Them hoc vien.\n";
        cout << "\t______________________________\n";
        cout << "\t Press 2. Hien thi ds hoc vien.\n";
        cout << "\t______________________________\n";
        cout << "\t Press 3. Sua thong tin hoc vien\n";
        cout << "\t______________________________\n";
        cout << "\t Press 4. Ghi ra File \n";
        cout << "\t Press 5. Doc du lieu tu File \n";
        cout << "\t______________________________\n";
        cout << "\t Press 0. Exit.\n";
        cout << "Press:";

        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6 && CatchKey != 0)
        {
            cout << "\nNO FEATURE!\nAgain: ";
        }

        switch (CatchKey)
        {
        case 1:
            DocFile(p);
            NhapHV(p);
            pressAnyKey();
            break;

        case 2:

            HienthiDS(p);
            pressAnyKey();
            break;

        case 3:
            SuaThongTin(p);
            pressAnyKey();
            break;
        case 4:
            GhiFile(p);
            pressAnyKey();
            break;
        case 5:
            DocFile(p);
            ShowALL(p);
            pressAnyKey();
            break;
        default:
            break;
        }
    } while (CatchKey != 0);
    cout << "Thanks!";
}