#include "temp.h"
#include <iostream>

using namespace std;

template < class T>
Queue<T>::Queue(int s)
{
    queueArray = new int[s];
    capacity = s;
    numItems = 0;
}

template < class T>
Queue<T>::~Queue()
{
    delete[] queueArray;
}

template < class T>
void Queue<T>::enqueue(int num)
{
    if (isFull())
        cout << "The queue is full.\n";
    else
    {
        queueArray[numItems] = num;
        numItems++;
    }
}

template < class T>
void Queue<T>::dequeue(int& num)
{
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        num = queueArray[0];
        for (int i = 0; i < numItems - 1; i++)
            queueArray[i] = queueArray[i + 1];
        numItems--;
    }
}

template < class T>
bool Queue<T>::isEmpty() const
{
    return numItems == 0;
}

template < class T>
bool Queue<T>::isFull() const
{
    return numItems == capacity;
}

template < class T>
void Queue<T>::display() const
{
    if (isEmpty())
    {
        cout << "The queue is empty.\n";
        return;
    }
    cout << "\nThese are elements of the Queue.\n";
    for (int i = 0; i < numItems; i++)
    {
        cout << queueArray[i] << endl;
    }
}


