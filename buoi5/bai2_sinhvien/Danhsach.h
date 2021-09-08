#include "Sinhvien.h"

class Danhsach
{
private:
    int n;
    vector<Sinhvien> sv;

public:
    Danhsach()
    {
        n = 0;
        sv.resize(0);
    }
    Danhsach(int n)
    {
        this->n = n;
    }
    void Nhap(vector<Sinhvien> &sv);
    void Xuat(vector<Sinhvien> &sv);
    void SinhvienMAX(vector<Sinhvien> &sv);
    void Sapxep(vector<Sinhvien> &sv);
    void pressAnyKey()
    {
        system("pause");
        getchar();
        system("cls");
    }
    void Feature();
};

void Danhsach::Feature()
{
    int temp;
    while (1)
    {
        cout << "\n________________________________________________________\n";
        cout << "Quan ly Sinh vien: ----------------------------------CTK \n";
        cout << "\t Press 1. Nhap.\n";
        cout << "\t Press 2. Xuat.\n";
        cout << "\t Press 3. Sinh vien diem cao nhat.\n";
        cout << "\t Press 4. Sap xep.\n";
        cout << "\t Press 0. THOAT.\n";
        while (cin >> temp && temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0)
        {
            cout << "\nJust press 1,2,3 or 4!\nAgain: ";
        }
        cout << "___________________________________________\n";
        switch (temp)
        {
        case 1:
            Nhap(sv);
            pressAnyKey();
            break;
        case 2:
            Xuat(sv);
            pressAnyKey();
            break;
        case 3:
            SinhvienMAX(sv);
            pressAnyKey();
            break;
        case 4:
            Sapxep(sv);
            pressAnyKey();
            break;
        case 0:
            cout << "Ban chon thoat. Tam biet\n";
            getchar();
            return;
        default:
            break;
        }
    }
}

void Danhsach::Nhap(vector<Sinhvien> &sv)
{
    cout << "Nhap n :";
    cin >> n;
    cout << "Nhap list ps \n";
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << "Nhap Sinh Vien thu " << i << " : \n";
        Sinhvien temp;
        temp.Nhap();
        sv.push_back(temp);
    }
}

void Danhsach::Xuat(vector<Sinhvien> &sv)
{
    for (int i = 0; i < sv.size(); i++)
    {
        /* code */
        sv[i].Show();
    }
}

struct SoSanh
{
    bool operator()(Sinhvien x, Sinhvien y)
    {
        if (x.getDiem() > y.getDiem())
        {
            return 1;
        }
        else if (x.getDiem() == y.getDiem())
        {
            return x.lastName[0] < y.lastName[0];
        }else{
            return 0;
        }
    }
};

void Danhsach::Sapxep(vector<Sinhvien> &a)
{
    sort(a.begin(), a.end(), SoSanh());
    cout << "Sau sap xep \n";
    for (int i = 0; i < a.size(); i++)
    {
        a[i].Show();
    }
}

void Danhsach::SinhvienMAX(vector<Sinhvien> &sv)
{
    Sinhvien max = sv[0];
    for (int i = 0; i < sv.size(); i++)
    {
        /* code */
        if (sv[i].getDiem() > max.getDiem())
        {
            max = sv[i];
        }
    }
    cout << "sinh vien diem cao nhat la : ";
    max.Show();
}
