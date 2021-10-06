#include "NhanVien.h"

class Quanli
{
    NhanVien NV[20];
    int n;

public:
    Quanli(int n)
    {
        this->n = n;
    }
    // Quanli(NhanVien *NV)
    // {
    //     for (int i = 0; i < sizeof(NV); i++)
    //     {
    //         this->NV = NV;
    //     }
    // }

    void Nhap()
    {
        // NV = new NhanVien[n];
        for (int i = 0; i < n; i++)
        {
            NV[i].Nhap();
        }
    }
    void Xuat()
    {

        for (int i = 0; i < n; i++)
        {
            NV[i].Xuat();
            cout << endl;
        }
    }
    void SapXepLL()
    {

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (NV[i].getTienluong() > NV[j].getTienluong())
                {
                    NV[i].swap(NV[j]);
                }
            }
        }
    }
    void SapXepT()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (NV[i].getTuoi() < NV[j].getTuoi())
                {
                    swap(NV[i], NV[j]);
                }
            }
        }
    }

    void SapXepLB()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (NV[i].getTienluong() < NV[j].getTienluong())
                {
                    swap(NV[i], NV[j]);
                }
            }
        }
    }

    bool cmp(NhanVien &a, NhanVien &b)
    {
        return a.getTienluong() < b.getTienluong();
    }
    void SapxepLuong()
    {
       sort(NV[0], NV[n-1], cmp);
    }

    void TimKiem()
    {
        float max = NV[0].getTienluong();
        for (int i = 0; i < n; i++)
        {
            if (NV[i].getTienluong() > max)
                max = NV[i].getTienluong();
        }

        for (int i = 0; i < n; i++)
        {
            if (NV[i].getTienluong() == max)
                NV[i].Xuat();
        }
    }
};
