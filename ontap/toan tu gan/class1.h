
#include <iostream>

using namespace std;

class object1{
    private:
        int a;
        double b;
    public:
        object1(){};
        ~object1(){};
        object1(int a, double b):a(a),b(b){};
        void print(){
            cout << a << ":"<< b <<endl;
        }
};