#include "NhanVien.h"

class QuanLy
{
    NhanVien *NV;
    int n;

public:
    QuanLy(int n)
    {
        this->n = n;
        NV = new NhanVien[n];
    }
    QuanLy(){};

    void Nhap()
    {
        cout << "Nhap so nhan vien : ";
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
                    swap(NV[i], NV[j]);
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

   
    void pressAnyKey()
    {
        system("pause");
        system("cls");
    }
};