#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vctBFS;
        vector<int> vctVisited(V, 0);
        queue<int> q;
        q.push(0);

        vctVisited[0] = 1;
        while (!q.empty())
        {
            int iNode = q.front();
            q.pop();
            vctBFS.push_back(iNode);
            for (int iCurrNode : adj[iNode])
            {
                if (!vctVisited[iCurrNode])
                {
                    q.push(iCurrNode);
                    vctVisited[iCurrNode] = 1;
                }
            }
        }

        return vctBFS;
    }
};

void printArray(vector<int> vctArr)
{
    for (auto it : vctArr)
    {
        cout << it << ", ";
    }
}

void Case1()
{
    int V = 5, E = 4;
    vector<int> vctAdj[5] = {
        {1,2,3},
        {0},
        {0,4},
        {0},
        {2}
    };

    Solution objSolution;
    vector<int> vctBFS = objSolution.bfsOfGraph(V, vctAdj);
    cout << endl << "Output BFS: [ ";
    printArray(vctBFS);
    cout << "\b\b]" << endl;
}

int main()
{
    Case1();
}

/*
Output BFS: [ 0, 1, 2, 3, 4]
*/