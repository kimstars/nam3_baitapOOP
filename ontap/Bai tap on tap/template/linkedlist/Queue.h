using namespace std;
#include <iostream>
#include "LinkedList.h"
#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue: public LinkedList<T>
{
  public:
		Queue();
		~Queue();
		
		void enqueue(T value);
		T dequeue();
		T& front();		
};


template <class T>
Queue<T>::Queue(){}

template <class T>		
Queue<T>::~Queue(){}

template <class T>		
void Queue<T>::enqueue(T value)
{
	LinkedList<T>::insertAtBack(value);
}

template <class T>	
T Queue<T>::dequeue()
{
	if(LinkedList<T>::isEmpty())
	{
		throw 2;
	}
	else
	{
		T firstElmnt = LinkedList<T>::firstNum();
		LinkedList<T>::removeFromFront();

		return firstElmnt;
	}
}

template <class T>	
T &Queue<T>::front()
{
	if(LinkedList<T>::isEmpty())
	{
		throw 3;
	}
	else
	{
		return LinkedList<T>::firstNum();
	}
}

#endif
