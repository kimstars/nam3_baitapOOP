#include "giaodich.h"

class GiaoDichTienTe: public GiaoDich {
    private:
        int tygia;
        string loaitiente;
    public:
        GiaoDichTienTe(){
            tygia = 0;
            loaitiente = "VND";
        }
        ~GiaoDichTienTe(){};
        void Nhap(){
            cout << "Nhap giao dich tien te: \n";
            GiaoDich::Nhap();
            cout << "Nhap ty gia : ";
            cin >> tygia;
            cout << "Nhap loai tien te : ";
            fflush(stdin);
            getline(cin,loaitiente);
            TinhTriGia();

        }
        void Xuat(){
            cout << "GD tien te: ";
            GiaoDich::Xuat();
            printf("Ty gia: %d| Loai TT: %s| Tri gia: %d\n",tygia,loaitiente,trigia);
        }
        void TinhTriGia(){
            trigia = soluong*dongia*tygia;
        }

};