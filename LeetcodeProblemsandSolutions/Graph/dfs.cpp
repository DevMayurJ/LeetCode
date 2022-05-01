#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> vctAdjList[], vector<int> &vctVisited, vector<int>& vctDFS)
    {
        if (!vctVisited[node])
        {
            vctDFS.push_back(node);
            vctVisited[node] = 1;
            for (int iCurrNode : vctAdjList[node])
            {
                if (!vctVisited[iCurrNode])
                {
                    dfs(iCurrNode, vctAdjList, vctVisited, vctDFS);
                }
            }
        }
    }

    vector<int> dfsOfGraph(int nVirtex, vector<int> vctAdjList[])
    {
        vector<int> vctDFS;
        vector<int> vctVisited(nVirtex + 1, 0);
        dfs(0, vctAdjList, vctVisited, vctDFS);
        return vctDFS;
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
    //vector<vector<int>> vctAdj(V, vector<int>(E));
/*
0 is connected to 1, 2, 4.
1 is connected to 0.
2 is connected to 0.
3 is connected to 4.
4 is connected to 0, 3.

// dfs will be 0 1 2 4 3.
*/
    vector<int> vctAdj[5] = {
        {1,2,4},
        {0},
        {0},
        {4},
        {0,3}
    };

    Solution objSolution;
    vector<int> vctDFS = objSolution.dfsOfGraph(V, vctAdj);
    cout << endl << "Output DFS: [ ";
    printArray(vctDFS);
    cout << "\b\b]" << endl;
}

void Case2()
{
    int V = 9,E = 9;
    vector<int> vctAdj[9] = {
        {2,5},
        {5,6,8},
        {0},
        {4,5 },
        {3, 7 },
        {0, 1, 3, 7},//5
        {1},
        {4,5},
        {1},
    };

    Solution objSolution;
    vector<int> vctDFS = objSolution.dfsOfGraph(V, vctAdj);
    cout << endl << "Output DFS: [ ";
    printArray(vctDFS);
    cout << "\b\b]" << endl;
}

int main()
{
    Case1();
    Case2();

}

