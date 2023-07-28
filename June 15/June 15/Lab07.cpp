#include <iostream>
#include <string>
using namespace std;

class IntStack
{

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

    IntStack operator= (IntStack& right)
    {
        delete[] stackArray;
        stackSize = right.stackSize;
        numElements = right.numElements;
            stackArray = new int[numElements];
        for (int i = 0; i < numElements; i++) {
            stackArray[i] = right.stackArray[i];
        }
        return *this;
    }

    IntStack(const IntStack& obj)
    {
        stackSize = obj.stackSize;
        numElements = obj.numElements;
        stackArray = new int[numElements];
        for (int i = 0; i < numElements; i++)
            stackArray[i] = obj.stackArray[i];
    }






};

IntStack::IntStack(int size) {
    stackArray = new int[size];
    stackSize = size;
    numElements = 0;
}
IntStack::~IntStack() {
    delete[]  stackArray;
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
void IntStack::pop(int& num)
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



int main() {

    int takeVar;
    IntStack stack1(6);

    stack1.push(2);
    stack1.push(4);
    stack1.push(6);
    stack1.push(8);
    stack1.push(10);
    stack1.push(12);

    stack1.display();

    cout << "Popping...\n";
    stack1.pop(takeVar);
    cout << takeVar << endl;
    stack1.pop(takeVar);
    cout << takeVar << endl;
    stack1.pop(takeVar);
    cout << takeVar << endl;
    stack1.pop(takeVar);
    cout << takeVar << endl;
    stack1.pop(takeVar);
    cout << takeVar << endl;

    stack1.display();


    int takeVar2;
    IntStack stack2(6);

    

    stack1.push(1);
    stack1.push(3);
    stack1.push(5);
    stack1.push(7);
    stack1.push(9);
    stack1.push(11);

    

    stack2 = stack1;
    stack2.display();

    cout << "Popping...\n";
    stack2.pop(takeVar2);
    cout << takeVar2 << endl;
    stack2.pop(takeVar2);
    cout << takeVar2 << endl;
    stack2.pop(takeVar2);
    cout << takeVar2 << endl;
    stack2.pop(takeVar2);
    cout << takeVar2 << endl;
    stack2.pop(takeVar2);
    cout << takeVar2 << endl;

    stack2.display();
    
   
    stack2.display();

   
    IntStack stack3 = stack1;


    stack3.display();



    return 0;
}



