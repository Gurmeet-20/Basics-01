#include <iostream>

using namespace std;

class Queue
{
private:
   int *queueArray;  
   int capacity;     
   int numItems;
public:
   Queue(int);
   ~Queue();
   void enqueue(int);
   void dequeue(int &);
   bool isEmpty() const;
   bool isFull() const;
   void display() const;
};
Queue::Queue(int s)
{
   queueArray = new int[s];
   capacity = s;
   numItems = 0;
}
Queue::~Queue()
{
   delete [] queueArray;
}
void Queue::enqueue(int num)
{
   if (isFull())
      cout << "The queue is full.\n";
   else
   {
      queueArray[numItems] = num;
      numItems++;
   }
}
void Queue::dequeue(int &num)
{
   if (isEmpty())
      cout << "The queue is empty.\n";
   else
   {
	   num = queueArray[0];
	   for (int i=0; i< numItems-1; i++)
		   queueArray[i]=queueArray[i+1];
       numItems--;
   }
}
bool Queue::isEmpty() const
{
   return numItems == 0;
}
bool Queue::isFull() const
{
   return numItems == capacity;
}
void Queue::display() const
{
    if (isEmpty())
    {
        cout << "The queue is empty.\n";
        return;
    }
    cout << "\nThese are elements of the Queue.\n";
    for (int i=0; i< numItems; i++)
    {
        cout << queueArray[i]<< endl;
    }
}
int main()
{
	Queue iQueue(5);
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
