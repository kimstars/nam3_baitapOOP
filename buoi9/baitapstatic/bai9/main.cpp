#include "Date.h"


int main(){
    Date a;
    a.Nhap();
    a.Xuat();
    bool check = a.NamNhuan(a.getYear());
    cout << check << endl;

    cout << "Kiem tra nam 2020 co nhuan khong : "<< Date::NamNhuan(2020);
    
}