#include "queue.h"

int main(){
    Queue<int> q;
    cout << "Enqueue : "<<endl;
    q.Enqueue(1);
    q.Enqueue(3);
    q.Enqueue(5);
    q.Enqueue(4);
    q.Enqueue(6);

    q.print();
    cout << "\nDequeue : "<<endl;
    cout << q.Dequeue();


    cout << "\nStack : "<<endl;

    Stack<char> S;
    S = S.Push('2');
    S = S.Push('3');
    S = S.Push('4');
    S = S.Push('6');

    cout <<"\nPop stack\n";
    cout << S.Pop();

    
}