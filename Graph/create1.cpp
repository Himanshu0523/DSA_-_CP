// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

class graph
{

public:
    unordered_map<int, vector<int>> adjList;

    // input are the [[u1 , v1] , [u2 , v2] , [u3 ,v3]]
    // output are u1 -> conneted edges , u2 ->

    vector<vector<int>> printAdjacentlist(int n, int m, vector<vector<int>> &edges)
    {
        vector<int> ans[n];
        // ans array will store all adjacent nodes
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            // given undirected Graph
            ans[u].push_back(v);
            ans[v].push_back(u);
        }

        vector<vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            adj[i].push_back(i);

            for (int j = 0; j < ans[i].size(); j++)
            {
                adj[i].push_back(ans[i][j]);
            }
        }
        return adj;
    }
};

int main() {
     return 0;
}