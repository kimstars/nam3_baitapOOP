#include <iostream>

using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node
{
    // Khai báo là hàm bạn để có thể sử dụng thuộc tính private trong Node
    friend class LinkedList<T>;

public:
    
    Node(const T &);

private:
    T data;
    Node<T> *next;
};

// dinh nghia nhung gi ta khai bao
template <typename T>
Node<T>::Node(const T &value)
{
    data = value;
    next = NULL;
}

template <typename T>
class LinkedList
{
public:
    LinkedList();        // khoi tao
    ~LinkedList();       // xoa
    void takeFront(T &); // dung tham tri
    void takeBack(T &);
    LinkedList<T> &insertAtFront(const T &);
    LinkedList<T> &insertAtBack(const T &);
    bool isEmpty() const;
	void print();
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *ptri;
    int size;
};

// dinh nghia cac thuoc tinh va phuong thuc cua lop doi tuong
template <typename T>
LinkedList<T>::LinkedList() : size(0), ptri(NULL)
{
    head = tail = NULL;
}
template <typename T>
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

template <typename T>
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
template <typename T>
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
template <typename T>
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

template <typename T>
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

template <typename T>
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