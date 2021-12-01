#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class GiaoDich {
    protected:
        string magiaodich;
        int ngaygiaodich;
        int dongia;
        int soluong;
        int trigia;

    public:
        GiaoDich(){
            magiaodich = "";
            ngaygiaodich = dongia = soluong = trigia =0;
        }
        ~GiaoDich(){};

        virtual void Nhap(){
            cout << "Nhap ma giao dich : ";
            fflush(stdin);
            getline(cin, magiaodich);
            // cin >> magiaodich;
            cout << "Nhap ngay giao dich :";
            cin >> ngaygiaodich;
            cout << "Nhap don gia :";
            cin >> dongia;
            cout << "Nhap so luong :";
            cin >> soluong;

        };
        virtual void Xuat(){
            printf("Ma giao dich: %s | Ngay giao dich: %d| Don gia: %d | So luong: %d| ",magiaodich, ngaygiaodich, dongia, soluong);

        }
        virtual void TinhTriGia(){};

        virtual int getTriGia(){
            return trigia;
        }

        virtual string getMaGiaoDich(){
            return magiaodich;
        }



};