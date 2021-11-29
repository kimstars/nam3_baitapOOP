#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack
{
    int top;
    int *a;
    int size;

public:
    Stack();
    Stack(int size);
    ~Stack();
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

Stack::~Stack()
{
    delete[] a;
}

Stack::Stack()
{
    top = -1;
    a = new int[MAX];
}

Stack::Stack(int size)
{
    top = -1;
    a = new int[size];
    this->size = size;
};

bool Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::isFull()
{
    return (top == size - 1 || top >= MAX);
}