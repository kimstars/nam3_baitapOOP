#include <bits/stdc++.h>

using namespace std;


int main(){
    int a[10] ;
    memset(a,0,9*sizeof(int));
    a[3] = 555;
    int b[10];
    memcpy(b, a, sizeof(a) );

    cout << b[3];
}