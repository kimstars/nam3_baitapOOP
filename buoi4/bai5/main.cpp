#include "Tamgiac.h"
#include "HCN.h"
#include "Tron.h"
#include "Point.h"


int main(){
    Point A(1,1);
    Point B(2,5);
    Point C(7,1);
    Tamgiac a(A, B , C);
    // cout << a.canhAB();

    Tron c(A, 5);
    cout << c.DienTich();
    HCN b;

}