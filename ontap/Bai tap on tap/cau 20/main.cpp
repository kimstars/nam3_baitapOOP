#include "stack.h"


int main(){
    Stack S;
    

    int n = 5;
    for(int i = 0 ; i < n; i++){
        S.push(i);
    }
    int x;
    while(!S.isEmpty()){
        cout << S.pop() << " ";
    }

}