/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MyStack{
    queue <int> q;
public:
    MyStack()
    {

    }

    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int iRet = q.front();
        q.pop();
        return iRet;
    }

    int top()
    {
        if (!empty())
        {
            return q.front();
        }

        return INT_MIN;
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack* obj = new MyStack();
    cout << "Push 10";
    obj->push(10);
    cout << "Push 20";
    obj->push(20);
    cout << "\nPop " << obj->pop();
    cout << "\ntop " << obj->top();
    cout << "\nempty " << obj->empty();
    cout << "\nPop " << obj->pop();
    cout << "\nempty " << obj->empty();
}

/*
Push 10Push 20
Pop 20
top 10
empty 0
Pop 10
empty 1
*/
