#include <bits/stdc++.h>

using namespace std;

// Depth First Search - for a Graph
// Depth First Search (DFS) starts from a given source vertex and explores one path as deeply as possible. When it reaches a vertex with no unvisited neighbors, it backtracks to the previous vertex to explore other unvisited paths. This continues until all vertices reachable from the source are visited.
// In a graph, there might be loops. So we use an extra visited array to make sure that we do not process a vertex again.

void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{
    visited[s] = true;
    res.push_back(s);

    // Recurseively visit all adjacent vertices that are not visited yet
    for (int i : adj[s])
    {
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
    }
}

vector<int> dfs(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;

    // Loop through all vertices
    // to handles disconnected graph
    for (int i = 0; i < adj.size(); i++){
        if (visited[i] == false){
            dfsRec(adj, visited, 0, res);
        }
    }
    return res;
}
