#pragma once
#include <bits/stdc++.h>
#include "Point.h"
using namespace std;

class Tamgiac : public Point
{
    private:
        Point A;
        Point B;
        Point C;
    public:
        Tamgiac(){
            A.Set(0,0);
            B.Set(0,0);
            C.Set(0,0);
        }
        Tamgiac(Point A, Point B, Point C){
            this->A = A;
            this->B = B;
            this->C = C;
        }

        double canhAB(){
            return A.khoangcach(B);
        }
        double canhBC(){
            return B.khoangcach(C);
        }
        double canhCA(){
            return C.khoangcach(A);
        }

        double DienTich(){
            double a = canhAB();
            double b = canhBC();
            double c = canhCA();

            double  p = (a + b + c)/2;
            double res = p*(p+a)*(p+b)*(p+c);
            return res;
        }

        

};