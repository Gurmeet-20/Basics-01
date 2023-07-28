#include <iostream>
#include <string>
using namespace std;
class IntStack
{
private:
    int* stackArray;
    int stackSize;
    int numElements;
public:
    IntStack(int);
    ~IntStack();

    void push(int);
    void pop(int&);
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
};
IntStack::IntStack(int Size)
{
    stackArray = new int[Size];
    stackSize = Size;
    numElements = 0;
}
IntStack::~IntStack()
{
    delete[] stackArray;
}
void IntStack::push(int num)
{
    if (isFull())
        cout << "The stack is full.\n";
    else
    {
        stackArray[numElements] = num;
        numElements++;
    }
}
void IntStack::pop(int &num)
{
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
    {
        numElements--;
        num = stackArray[numElements];
    }
}
bool IntStack::isFull() const
{
    return numElements == stackSize;
}
bool IntStack::isEmpty() const
{
    return numElements == 0;
}
void IntStack::display() const
{
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
        for (int i = 0; i < numElements; i++)
            cout << stackArray[i] << "\t";
    cout << endl;
}
int main()
{
    int catchVar;
    IntStack myStack(5); // Define a stack object to hold 5 values.
    // Push the values 5, 10, 15, 20, and 25 onto the stack.
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(20);
    myStack.push(25);
    myStack.push(30);

    myStack.display();

    // Pop the values off the stack.
    cout << "Popping...\n";
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.display();
    myStack.pop(catchVar);
    cout << catchVar << endl;
    myStack.pop(catchVar);
    cout << catchVar << endl;

    myStack.display();
    return 0;
}


