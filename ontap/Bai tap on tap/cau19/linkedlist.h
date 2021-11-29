#include <iostream>

using namespace std;

//Linked list nhưng mà nó là queue
template <typename T>
class LLQueue;


template <typename T>
class Node
{
    // Khai báo là hàm bạn để có thể sử dụng thuộc tính private trong Node
    friend class LLQueue<T>;

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
class LLQueue
{
public:
    LLQueue();        // khoi tao
    ~LLQueue();       // xoa
    void takeFront(T &); // dung tham tri
    void takeBack(T &);

    LLQueue<T> &Enqueue(const T &);
    bool isEmpty() const;
	void print();

    T Dequeue();
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *ptri;
    int size;
};

// dinh nghia cac thuoc tinh va phuong thuc cua lop doi tuong
template <typename T>
LLQueue<T>::LLQueue() : size(0), ptri(NULL)
{
    head = tail = NULL;
}
template <typename T>
LLQueue<T>::~LLQueue()
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
LLQueue<T> &LLQueue<T>::Enqueue(const T &value)
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
T LLQueue<T>::Dequeue()
{
    T retval;
    if (ptri == head)
        ptri = NULL;
    if (size == 0)
        return;
    Node<T> *tempPtr = head;
    head = tempPtr->next;
    retval = tempPtr->data;
    delete tempPtr;
    --size;
    return retval;
}



template <typename T>
bool LLQueue<T>::isEmpty() const
{
    return (size > 0) ? false : true;
}


template <class T>
void LLQueue<T>::print()
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


