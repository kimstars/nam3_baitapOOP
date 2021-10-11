#include <iostream>

using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date(){};
    Date(int day, int month, int year) : day(day), month(month), year(year){};
    void Nhap()
    {
        cout << "Nhap ngay :";
        cin >> day;
        cout << "Nhap thang :";
        cin >> month;
        cout << "Nhap nam :";
        cin >> year;
    }
    void Xuat()
    {
        cout << "Ngay: " << day << endl;
        cout << "Thang: " << month << endl;
        cout << "Nam: "<< year << endl;
    }
    int getYear(){
        return year;
    }
    static bool NamNhuan(int year)
    {
        if (year % 400 == 0)
            return true;
        if (year % 4 == 0 && year % 100 != 0)
            return true;
        return false;
    }
};