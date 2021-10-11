
#include "nhanvien.h"

class Quanly
{
private:
    Nhanvien *nv;
    int n;

public:
    void inti()
    {
        cout << "Nhap so nhan vien :";
        cin >> n;
        nv = new Nhanvien[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap nv " << i << endl;
            nv[i].Nhap();
        }
    }

    void Sapxep()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nv[i].getluong() < nv[j].getluong())
                {
                    swap(nv[i], nv[j]);
                }
            }
        }
    }
    bool cmp(Nhanvien a, Nhanvien b)
    {
        return a.getluong() < b.getluong();
    }

    struct cmp{
        bool operator()(const Nhanvien struct1, const Nhanvien struct2){
            return (struct1.getluong() < struct2.getluong());
    }
    };
void sortluong()
{
    sort(nv, nv+n, cmp());
}
void XuatThongtin()
{
    for (int i = 0; i < n; i++)
    {
        nv[i].Xuat();
    }
}
}
;