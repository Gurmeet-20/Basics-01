

#include <iostream>
#include "IntQueue.h"
#include "IntQueue.cpp"

using namespace std;


int main()
{
	Queue<int> iQueue(5);
	int catchVar;
	iQueue.enqueue(5);
	iQueue.display();
	iQueue.enqueue(12);
	iQueue.display();
	iQueue.enqueue(8);
	iQueue.display();
	iQueue.enqueue(15);
	iQueue.display();
	iQueue.enqueue(17);
	iQueue.display();
	iQueue.enqueue(5);
	iQueue.display();

	iQueue.dequeue(catchVar);
	iQueue.display();
	iQueue.dequeue(catchVar);
	iQueue.display();
	iQueue.enqueue(99);
	iQueue.display();
	return 0;
}