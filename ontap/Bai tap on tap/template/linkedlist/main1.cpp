#include <iostream>

#include "LinkedList.h"
using namespace std;


int main()
{
    LinkedList<int> l;
    l.insertAtBack(1);
    l.insertAtBack(1);
    l.insertAtBack(1);
    l.insertAtBack(1);
    l.insertAtBack(2);

    l.print();

}