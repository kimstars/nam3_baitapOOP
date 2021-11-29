#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
using namespace std;

int main()
{
  try
	{
		int type = 0;

		cout<<"What data type do you want to work with? 1 = int, 2 = char, 3 = string"<<endl;
		cin>>type;

		if(type == 1)
		{
			Queue <int> q;
			q.enqueue(1);
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;
			
			q.enqueue(3);
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;
			
			q.enqueue(5);
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;
			
			q.dequeue();
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;

			q.dequeue();
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;

			q.dequeue();
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;
		}

		if (type == 2)
		{
			Queue <char> q;
			
			q.enqueue('a');
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;

			q.enqueue('b');
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;

			q.enqueue('c');
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;

			q.dequeue();
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;

			q.dequeue();
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;

			q.dequeue();
			cout<<"The size is: "<< q.size() <<". And the top is: " << q.front() <<endl;
		}

		return 1;
	}
	catch (int e)
	{
		if (e == 2)
		{
			cout<<"Call to dequeue() generated an exception, because the queue is empty."<<endl;
		}
		else if (e == 3)
		{
			cout<<"Call to front() generated an exception, because the queue is empty."<<endl;
		}
	}
}