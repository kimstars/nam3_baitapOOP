#include "queue.h"


int main(){
    Queue<int> Q;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        Q.push(i);
    }

    while(!Q.isEmpty()){
        cout << Q.pop() << "\t";
    }
    
}