// DFS for complete Traversal of Disconnected Directed Graphs

#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
}

// Recursive function foe DFS Traversal
void DFSRec(vector<vector<int>> & adj, vector<bool> &visited, int s)
{
    // Mark the current vertex as visited.
    visited[s] = true;

    // Print the current vertex
    cout << s << " ";

    // Recursively visit all adjacent vertices that are not visited yet
    for (int i : adj[s])
    {
        if (visited[i] == false)
            DFSRec(adj, visited, i);
    }
}

// Main DFS function to prefyetorm DFS for the entire graph
void DFS(vector<vector<int>> &adj) {
    vector<bool> visited(adj.size() , false);

    //Loop through all vertice to handle disconnected graph
    for (int i = 0; i< adj.size();i++) {
        if (visited[i] == false) {
            // if vertex i has not been visited perform DFS from it
            DFSRec(adj , visited , i);
        }
    }
}

int main() {
    int V = 6;
    // Create an adjaceny list for the graph 
    vector<vector<int>> adj(V);

    // Defines the edges of the graph 
    vector<vector<int>> edges = {{1, 2}, {2, 8}, {0, 3} , {4 ,5}};

    // Populae the adjacency list with edges 
    for(auto  &e : edges)
        addEdges(adj , e[0] , e[1]);

    cout << "Complete DFS of the graph:" << endl;
    DFS(adj);

    return 0;
}