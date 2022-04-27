/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
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
