#pragma once
#include <bits/stdc++.h>
using namespace std;

class Tamgiac
{
    private:
        double A;
        double B;
        double C;
    public:
        Tamgiac(){
            A = B =C =0;
        }
        Tamgiac(double A, double B, double C){
            this->A = A;
            this->B = B;
            this->C = C;
        }
        void Nhap(){
            
        }

        double canhAB(){
            return A;
        }
        double canhBC(){
            return B;
        }
        double canhCA(){
            return C;
        }

        double DienTich(){
            double  p = (A + B + C)/2;
            double res = p*(p+A)*(p+B)*(p+C);
            return res;
        }

        

};