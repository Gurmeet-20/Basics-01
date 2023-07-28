#pragma once
#include <iostream>


using namespace std;


template < class T>
class Queue
{
private:
	T* queueArray;
	int capacity;
	int numItems;
public:
	Queue(int);
	~Queue();
	void enqueue(int);
	void dequeue(int&);
	bool isEmpty() const;
	bool isFull() const;
	void display() const;
};

