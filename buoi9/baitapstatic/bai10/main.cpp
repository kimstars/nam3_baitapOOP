#include "Date.h"

int main()
{
    Date a;
    a.Nhap();
    Date b;
    b.Nhap();

    
    int res = Date::tinhNgay(a,b);
    cout << res;
}