#include <iostream>

using namespace std;

class testclass{
    public:
        int a;
};

struct teststruct{
    private:
        int a;
    public:
    void seta(){
        a = 10;
    }
};



int main(){
    testclass n1;
    teststruct n2;

    n1.a = 0;
    n2.seta();

    




}