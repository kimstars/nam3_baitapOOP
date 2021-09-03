#pragma once
#include <bits/stdc++.h>
using namespace std;


class Point{
    private:
        int x;
        int y;
    public:
        Point(){
            x=y=0;
        }
        Point(int x, int y){
            this->x = x;
            this->y = y;
        };
        ~Point(){
            x=y=0;
        }
        void Set(int x, int y){
            this->x = x;
            this->y = y;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        double khoangcach(Point B){
            double res = sqrt(pow((x-B.x),2) + pow((y-B.y),2));
            return res;   
        }
        void show(){
            cout << "x = "<< x <<endl;
            cout << "y = " << y <<endl;
        }
};