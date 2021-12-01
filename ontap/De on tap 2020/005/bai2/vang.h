#include "giaodich.h"

class GiaoDichVang: public GiaoDich {
    private:
        string loaiVang;
    public:
        GiaoDichVang(){
            loaiVang = "9999";
            trigia = 0;
        }

        ~GiaoDichVang(){};

        void Nhap(){
            cout << "Nhap giao dich vang: \n";
            GiaoDich::Nhap();
            cout << "Nhap loai vang : ";
            fflush(stdin);
            getline(cin, loaiVang);
            // cin >> loaiVang;
            TinhTriGia();

        }
        void Xuat(){
            cout << "GD vang: ";
            GiaoDich::Xuat();
            printf("Loai vang: %s| Tri gia: %d\n",loaiVang,trigia);
        }
        void TinhTriGia(){
            trigia = soluong*dongia;
        }

};