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
        while (day > 31 || day <= 0)
        {
            cout << "Nhap ngay :";
            cin >> day;
        }
        cout << "Nhap thang :";
        cin >> month;

        while (month > 12 || month <= 0)
        {
            cout << "Nhap thang :";
            cin >> month;
        }
        cout << "Nhap nam :";
        cin >> year;
    }
    void Xuat()
    {
        cout << "Ngay: " << day << endl;
        cout << "Thang: " << month << endl;
        cout << "Nam: " << year << endl;
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    static bool NamNhuan(int year)
    {
        if (year % 400 == 0)
            return true;
        if (year % 4 == 0 && year % 100 != 0)
            return true;
        return false;
    }

     static void SoNgayTrongThang(int month,int year)
    {
        cout << "Thang " << month;
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << " co 31 ngay\n";
            break;
        case 2:
            if (NamNhuan(year))
            {
                cout << " co 29 ngay\n";
            }
            else
            {
                cout << " co 28 ngay\n";
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << " co 30 ngay\n";
            break;
        default:
            break;
        }
    }
};