#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

template <class Type>
class Queue
{
private:
    int front, back;
    int size;
    Type *a;

public:
    Queue()
    {
        front = back = -1;
        a = new Type[MAX];
        size = MAX;
    }
    Queue(int size)
    {
        front = back = -1;
        this->size = size;
        a = new Type[size];
    }
    bool push(Type x);
    Type pop();
    Type peek();
    bool isEmpty();
    bool isFull();
};

template <class Type>
bool Queue<Type>::push(Type x)
{
    if(isFull()){
        cout << "Overflow\n";
        return 0;
    }
    cout << "push " << x << "to Queue \n";
    if(isEmpty()){
        back+=2;front++;
        a[front] = a[back] = x;
        return 1;
    }else{
        a[back++] = x;
        return 1;
    }
}

template <class Type>
Type Queue<Type>::pop()
{
    if(isEmpty()){
        cout << "Underflow\n";
    }else{
        return a[front++];
    }

}
template <class Type>
Type Queue<Type>::peek()
{
    if(isEmpty()){
        cout << "Underflow\n";
    }else{
        return a[front];
    }
}

template <class Type>
bool Queue<Type>::isEmpty()
{
    return front == back;
}

template <class Type>
bool Queue<Type>::isFull()
{
    return front > size;
}
