#include "Date.h"

int main()
{
    Date a(12, 4, 2000);
    // a.Nhap();
    a.SoNgayTrongThang(a.getMonth(),a.getYear());
    int month;
    cout << "Kiem tra so ngay trong thang.\nNhap thang: ";
    cin >> month;
    while (month > 12 || month <= 0)
    {
        cout << "Nhap thang :";
        cin >> month;
    }

    Date::SoNgayTrongThang(month,a.getYear());
}