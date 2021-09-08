#include "PhanSo.h"

class DayPS : public Phanso
{
private:
    int n;
    vector<Phanso> listPS;

public:
    DayPS()
    {
        n = 0;
        listPS.resize(0);
    }

    void Nhap(vector<Phanso> &);
    void Xuat(vector<Phanso> &);
    void Sapxep(vector<Phanso> &);
    void Feature();
    bool cmp(Phanso p1, Phanso p2);
    void PhansoMax(vector<Phanso> &listPS);

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
        cout << "\t Press 1. Nhap.\n";
        cout << "\t Press 2. Xuat.\n";
        cout << "\t Press 3. Phan so lon nhat.\n";
        cout << "\t Press 4. Sap xep.\n";
        cout << "\t Press 0. THOAT.\n";
        while (cin >> temp && temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0)
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
            PhansoMax(listPS);
            pressAnyKey();
            break;
        case 4:
            Sapxep(listPS);
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

void DayPS::Nhap(vector<Phanso> &listPS)
{
    cout << "Nhap n :";
    cin >> n;
    cout << "Nhap list ps \n";
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << "Nhap phan so thu " << i << " : \n";
        Phanso temp;
        temp.nhap();
        listPS.push_back(temp);
    }
}

void DayPS::Xuat(vector<Phanso> &listPS)
{
    for (int i = 0; i < listPS.size(); i++)
    {
        /* code */
        listPS[i].in();
    }
}

void DayPS::PhansoMax(vector<Phanso> &listPS)
{
    Phanso max = listPS[0];
    for (int i = 0; i < listPS.size(); i++)
    {
        /* code */
        if (listPS[i] > max)
        {
            max = listPS[i];
        }
    }
    cout << "Phan so lon nhat la : ";
    max.in();
}

struct SoSanh
{
    bool operator()(Phanso x, Phanso y)
    {
        return x > y;
    }
};

void DayPS::Sapxep(vector<Phanso> &a)
{
    sort(a.begin(), a.end(), SoSanh());

    for (int i = 0; i < listPS.size(); i++)
    {
        /* code */
        a[i].in();
    }
}
