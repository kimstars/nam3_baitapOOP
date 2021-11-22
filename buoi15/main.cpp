#include "PhanSo.h"


using namespace std;

int main(){
    PhanSo *ps;
    PhanSo a(1,2);
    ps = &a;
    cout << *ps;
}