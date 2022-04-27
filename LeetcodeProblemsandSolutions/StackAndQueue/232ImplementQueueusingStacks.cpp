/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
*/

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
    stack<int> stInput;
    stack<int> stOutput;
public:
    MyQueue() {

    }

    void push(int x)
    {
        while (!stInput.empty())
        {
            stOutput.push(pop());
        }

        stInput.push(x);
        while (!stOutput.empty())
        {
            stInput.push(stOutput.top());
            stOutput.pop();
        }
    }

    int pop()
    {
        int iRet = peek();
        stInput.pop();
        return iRet;
    }

    int peek()
    {
        if (stInput.empty())
        {
            exit(0);
        }

        return stInput.top();
    }

    bool empty()
    {
        return stInput.empty();
    }
};

int main()
{
     MyQueue* obj = new MyQueue();
     cout << "obj->push 10" << "\n";
     obj->push(10);
     cout << "obj->empty()" << obj->empty() << "\n";   
     cout << "obj->peek()" << obj->peek() << "\n";
     cout << "obj->pop()" << obj->pop() << "\n";
     cout << "obj->empty()" << obj->empty() << "\n";   
}

/*
obj->push 10
obj->empty()0
obj->peek()10
obj->pop()10
obj->empty()1
*/
