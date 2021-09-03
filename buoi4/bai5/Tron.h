#pragma once
#include <bits/stdc++.h>
#include "Point.h"
using namespace std;
#define Pi 3.14


class Tron : public Point
{
    private:
        Point tam;
        double R;
    public:
        Tron(){
            tam.Set(0,0);
            R = 0;
        }

        Tron(Point A, double R){
            this->tam = A;
            this->R = R;
        }

        double DienTich(){
            return Pi*pow(R,2);
        }

        void Nhap(){
            cout << "Nhap toa do tam ";
        }

};