#include<bits/stdc++.h>

using namespace std;

// fiunction to add an edge to the adjacency list 
void addEdge(vector<vector<int>> &adj , int s, int t) {
    // Add edges from vertex s to t
    adj[s].push_back(t);
}

// Recursive function ffor dfs traversal
void DFSRec (vector<vector<int>> &adj , vector<bool> &visited , int s ) {
    // Mark the current vertex as visited
    visited[s] = true;

    // Print the current vertex
    cout << s << " ";

    //Recursively visit all adjacent vertices that yet
    for (int i : adj[s]) {
        if (visited[i] == false)
            DFSRec(adj , visited , i);
    }
}


// main DFS function that initializes the visited array and call DFSRec
void DFS(vector<vector<int>> &adj, int s ){
    vector<bool> visited(adj.size() , false);

    //Call the recursive DFS function
    DFSRec(adj , visited , s);
}

int main() {
    int V = 5;

    //Create an adjacency list foe the graph 
    vector<vector<int>> adj(V);

    //Drfines the edges of the graph
    vector<vector<int>> edges = {{1, 2} , {1, 0} , {2, 2}};

    // Populates the adjacency list with edges 
    for (auto &e : edges) {
        addEdge(adj , e[0] , e[1]);
    }

    int source = 1;
    cout << "DFS from sources : " << source << endl;
    DFS(adj , source);

    return 0;
}