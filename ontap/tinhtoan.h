#include <bits/stdc++.h>


using namespace std;

class tinhtong{
    private:
        int a,b,c;
        int tong;
    public:
        tinhtong(int a, int b, int c):a(a),b(b), c(c){
            tong = a + b + c;
        };
        tinhtong(int a, int b):a(a),b(b){
            tong = a + b ;
        };
        int getTong(){
            return tong;
        }
};