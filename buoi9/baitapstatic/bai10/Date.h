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

    static void SoNgayTrongThang(int month)
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

    static int tinhNgay(Date a,Date b){
        int date = 0;
        int dateOfMonth = 0;
        int dateOfYear = 0;
        
        for (int i = a.year; i < b.year ; i++)
        {
            if(NamNhuan(i)){
                dateOfYear += 366;
            }else{
                dateOfYear += 365;
            }
        }
        int dateMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

        if (NamNhuan(b.year)) dateMonth[1]=29;  
        
        if(a.month > b.month){
            for (int i = a.month; i < b.month; i++)
            {
                dateOfMonth -= dateMonth[i-1];
            }
        }else{
            for (int i = a.month; i < b.month; i++)
            {
                dateOfMonth += dateMonth[i-1];
            }
        }

        date = b.day - a.day + 1;

        return date + dateOfMonth + dateOfYear;
    }
};