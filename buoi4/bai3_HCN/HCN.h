#pragma once
#include <bits/stdc++.h>
#include "Point.h"
using namespace std;

class HCN : public Point
{
private:
    Point start;
    Point end;

public:
    HCN()
    {
        start.Set(0, 0);
        end.Set(0, 0);
    }
    HCN(int x1, int y1, int x2, int y2)
    {
        start.Set(x1, y1);
        end.Set(x2, y2);
    }

    HCN(Point start, Point end) : start(start), end(end){};

    void show()
    {
        cout << "x1 = " << start.getX() << endl;
        cout << "y1 = " << start.getY() << endl;
        cout << "x2 = " << end.getX() << endl;
        cout << "y3 = " << end.getY() << endl;
    }

    void Nhap()
    {
        int x, y;
        cout << "nhap toa do (x1, y1) : ";
        cin >> x >> y;
        start.Set(x, y);
        cout << "nhap toa do (x2, y2) : ";
        cin >> x >> y;
        end.Set(x, y);
    }
    double ChieuRong(){
        return  abs(end.getX() - start.getX());
    }
    double ChieuDai(){
        return abs(start.getY() - end.getY());
    }
    double dientich(){
        return this->ChieuDai()* this->ChieuRong();
    }

    bool GiaoNhau(HCN B){
        bool onOx = (start.getX() <= B.end.getX() && B.start.getX() <= end.getX());
        bool onOy = (start.getY() <= B.end.getY() && B.start.getY() <= end.getY());
        return onOx && onOy;
    }

    double DienTichGiaonhau(HCN B){
        if(this->GiaoNhau(B)){
            //chieu rong
            Point a(max(start.getX(),B.start.getX()) , min( (start.getY()+ end.getX()) , (B.start.getY()+ B.end.getX())));
            Point b(max(start.getY(),B.start.getY()) , min( (start.getX()+ end.getX()) , (B.start.getX()+ B.end.getX())));
            a.show();
            b.show();
            return 0;
        }else{
            cout << "Khong giao nhau";
            return -1;
        }
    }
};