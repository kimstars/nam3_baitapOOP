#include <iostream>

using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node
{
    // khai bao LinkedList co the dung cac thuoc tinh duoc bao ve trong 'Node'
    friend class LinkedList<T>;

public:
    
    Node(const T &);

private:
    T data;
    Node<T> *next;
};

// dinh nghia nhung gi ta khai bao
template <class T>
Node<T>::Node(const T &value)
{
    data = value;
    next = NULL;
}

template <class T>
class LinkedList
{
public:
    LinkedList();        // khoi tao
    ~LinkedList();       // xoa
    void takeFront(T &); // dung tham tri
    void takeBack(T &);
    LinkedList<T> &insertAtFront(const T &);
    LinkedList<T> &insertAtBack(const T &);
    virtual bool isEmpty() const;   
    void print();

private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *ptri;
    int size;
};

// dinh nghia cac thuoc tinh va phuong thuc cua lop doi tuong
template <class T>
LinkedList<T>::LinkedList() : size(0), ptri(NULL)
{
    head = tail = NULL;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    if (size > 0)
    {
        Node<T> *curPtr = head;
        Node<T> *tempPtr;
        while (curPtr != 0)
        {
            tempPtr = curPtr;
            curPtr = curPtr->next;
            delete tempPtr;
        }
    }
}

template <class T>
LinkedList<T> &LinkedList<T>::insertAtFront(const T &value)
{
    Node<T> *tempPtr = new Node<T>(value);
    if (tempPtr == NULL)
    {
        cout << "Tran bo nho" << endl;
        return *this;
    }
    if (size == 0)
    {
        head = tail = tempPtr;
    }
    else
    {

        tempPtr->next = head;
        head = tempPtr;
    }
    ++size;
    ptri = head;
    return *this;
}
template <class T>
LinkedList<T> &LinkedList<T>::insertAtBack(const T &value)
{
    Node<T> *tempPtr = new Node<T>(value);
    if (tempPtr == NULL)
    {
        cout << "Tran bo nho" << endl;
        return *this;
    }
    if (size == 0)
    {
        head = tail = ptri = tempPtr;
    }
    else
    {

        tail->next = tempPtr;
        tail = tempPtr;
    }
    ++size;
    ptri = head;
    return *this;
}
template <class T>
void LinkedList<T>::takeFront(T &i)
{
    if (ptri == head)
        ptri = NULL;
    if (size == 0)
        return;
    Node<T> *tempPtr = head;
    head = tempPtr->next;
    i = tempPtr->data;
    delete tempPtr;
    --size;
}

template <class T>
void LinkedList<T>::takeBack(T &i)
{
    if (ptri == tail)
        ptri = NULL;
    if (size == 0)
        return;
    Node<T> *tempPtr = head;
    if (tempPtr == tail)
    {
        i = tail->data;
        delete tempPtr;
        head = tail = ptri = NULL;
        --size;
        return;
    }
    while (tempPtr->next != tail)
        tempPtr = tempPtr->next;
    i = tail->data;
    delete tail;
    tail = tempPtr;
    tempPtr->next = NULL;
    --size;
}
template <class T>
bool LinkedList<T>::isEmpty() const
{
    return (size > 0) ? false : true;
}

template <class T>
void LinkedList<T>::print()
{
    Node<T> *temp = head;

    if (temp == NULL)
    {
        cout << "";
    }

    if (temp->next == NULL)
    {
        cout << temp->data;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
            cout << "  ";
        }
    }
}




//định nghĩa template stack kế thừa 
template <class T>
class Stack : private LinkedList<T>
{
public:
    Stack &Push(const T &rval)
    {
        LinkedList<T>::insertAtBack(rval);
        return *this;
    }
    T Pop()
    {
        T retval;
        LinkedList<T>::takeBack(retval);
        return retval;
    }
    // bool isEmpty() const { return LinkedList::isEmpty(); }
};




//định nghĩa template Queue kế thừa LinkedList
template <class T>
class Queue : public LinkedList<T>
{
public:
    void Enqueue(const T &rval)
    {
        LinkedList<T>::insertAtBack(rval);
    }
    T Dequeue()
    {
        T retval;
        LinkedList<T>::takeFront(retval);
        return retval;
    }
    // bool isEmpty() const { return LinkedList::isEmpty(); }
};

