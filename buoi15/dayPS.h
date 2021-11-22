#include "PhanSo.h"

class DayPS : public PhanSo
{
private:
    int n;
    vector<PhanSo> listPS;

public:
    DayPS()
    {
        n = 0;
        listPS.resize(0);
    }

    void Nhap(vector<PhanSo> &);
    void Xuat(vector<PhanSo> );
    void Sapxeptangdan(vector<PhanSo> &);
    void Sapxepgiamdan(vector<PhanSo> &);
    void Feature();
    bool cmp(PhanSo p1, PhanSo p2);
    void PhanSoMax(vector<PhanSo> &listPS);
    void TongDay(vector<PhanSo> listPS);
    void NhanVoid(vector<PhanSo> &listPS);

    void pressAnyKey()
    {
        system("pause");
        getchar();
        system("cls");
    }
};

void DayPS::Feature()
{
    int temp;
    while (1)
    {
        cout << "\n________________________________________________________\n";
        cout << "Chuc nang KHAC: \n";
        cout << "\t Press 1. Nhap phan so.\n";
        cout << "\t Press 2. Xuat phan so.\n";
        cout << "\t Press 3. Phan so lon nhat.\n";
        cout << "\t Press 4. Sap xep tang dan.\n";
        cout << "\t Press 5. Sap xep giam dan.\n";
        cout << "\t Press 6. Tong day phan so.\n";
        // cout << "\t Press 7. Nhan day phan so voi mot so nguyen.\n";
        cout << "\t Press 0. THOAT.\n";
        while (cin >> temp && temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 5 && temp != 6&& temp != 7 && temp != 0)
        {
            cout << "\nJust press 1,2 or 3!\nAgain: ";
        }
        cout << "___________________________________________\n";
        switch (temp)
        {
        case 1:
            Nhap(listPS);
            pressAnyKey();
            break;
        case 2:
            Xuat(listPS);
            pressAnyKey();
            break;
        case 3:
            // Sapxep(listPS);
            PhanSoMax(listPS);
            pressAnyKey();
            break;
        case 4:
            Sapxeptangdan(listPS);
            pressAnyKey();
            break;
        case 5:
            Sapxepgiamdan(listPS);
            pressAnyKey();
            break;
        case 6:
            TongDay(listPS);
            pressAnyKey();
            break;
        case 7:
            NhanVoid(listPS);
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

void DayPS::Nhap(vector<PhanSo> &listPS)
{
    cout << "Nhap n :";
    cin >> n;
    cout << "Nhap list ps \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i << " : \n";
        PhanSo temp;
        cin >> temp;
        listPS.push_back(temp);
    }
}

void DayPS::Xuat(vector<PhanSo> listPS)
{
    for (int i = 0; i < listPS.size(); i++)
    {
        cout << listPS[i];
    }
}

void DayPS::PhanSoMax(vector<PhanSo> &listPS)
{
    PhanSo max = listPS[0];
    for (int i = 0; i < listPS.size(); i++)
    {
        if (listPS[i] > max)
        {
            max = listPS[i];
        }
    }
    cout << "Phan so lon nhat la : ";
    cout << max;
}

struct sosanhgiam
{
    bool operator()(PhanSo x, PhanSo y)
    {
        return x > y;
    }
};

struct sosanhtang
{
    bool operator()(PhanSo x, PhanSo y)
    {
        return x < y;
    }
};
void DayPS::Sapxeptangdan(vector<PhanSo> &a)
{
    sort(a.begin(), a.end(), sosanhtang());
    cout << "\nSap xep theo thu tu tang dan\n";
    for (int i = 0; i < a.size(); i++)
    {
        /* code */
        cout << a[i];
    }
}

void DayPS::Sapxepgiamdan(vector<PhanSo> &a)
{
    sort(a.begin(), a.end(), sosanhgiam());
    cout << "\nSap xep theo thu tu giam dan\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
}

void DayPS::TongDay(vector<PhanSo> listPS)
{
    PhanSo tong = listPS[0];
    for (int i = 1; i < listPS.size(); i++)
    {
        tong += listPS[i];
    }
    cout << "tong = " << tong;
}

void DayPS::NhanVoid(vector<PhanSo> &listPS)
{
    int d;
    cout << "\nNhap gia tri muon nhan : ";
    cin >> d;
    for (int i = 1; i < listPS.size(); i++)
    {
        listPS[i] = listPS[i] * d;
    }
    cout << "\nDay sau khi nhan tat ca voi " << d << " :\n";
    Xuat(listPS);
}
