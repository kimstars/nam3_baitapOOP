#include "Date.h"

int main()
{
    Date a(12, 2, 2000);
    // a.Nhap();
    Date b(12, 3, 2000);
    
    int res = Date::tinhNgay(a,b);
    cout << res;
}