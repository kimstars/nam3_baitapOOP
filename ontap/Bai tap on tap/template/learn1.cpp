#include <bits/stdc++.h>
using namespace std;
template <class val>
void swapVal(val &a , val &b)
{
     val temp;
     temp = a;
     a = b;
     b = temp;
}


template <class temp>
temp sum(temp a, temp b){
    return a + b;
}

int main()
{
    int intX = 2, intY = 3;
    
    cout << sum(intX,intY);

}