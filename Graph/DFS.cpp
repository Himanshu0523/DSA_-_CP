#include <bits/stdc++.h>
using namespace std;

class DFS {
public:
    unordered_map<int, list<int>> AdjacentList;
    vector<vector<int>> AdjacentMatrix;

    // Convert Edge List to Adjacency List
    void Convert_AdjList(vector<vector<int>> &GivenList, bool isDirectedGraph = false) {
        for (const auto &edge : GivenList) {
            int a = edge[0], b = edge[1];
            AdjacentList[a].push_back(b);
            if (!isDirectedGraph) { // Add reverse edge only for undirected graphs
                AdjacentList[b].push_back(a);
            }
        }
    }

    // Convert Edge List to Adjacency Matrix
    void Convert_AdjMatrix(int vertex, vector<vector<int>> &GivenList, bool isDirectedGraph = false) {
        AdjacentMatrix = vector<vector<int>>(vertex, vector<int>(vertex, 0));
        for (auto &edge : GivenList) {
            int a = edge[0], b = edge[1];
            AdjacentMatrix[a][b] = 1;
            if (!isDirectedGraph) { // Add reverse edge only for undirected graphs
                AdjacentMatrix[b][a] = 1;
            }
        }
    }

    // DFS Traversal
    void dfs(unordered_map<int, list<int>> &AdjList, unordered_map<int, bool> &visited, vector<int> &component, int node) {
        component.push_back(node);
        visited[node] = true;

        for (int neighbour : AdjList[node]) {
            if (!visited[neighbour]) {
                dfs(AdjList, visited, component, neighbour);
            }
        }
    }

    // Perform DFS and Print Components
    void Print_DFS_List(int vertex, vector<vector<int>> &GivenList) {
        Convert_AdjList(GivenList); // Build adjacency list
        vector<vector<int>> ans; // Store connected components
        unordered_map<int, bool> visited;

        for (int i = 0; i < vertex; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(AdjacentList, visited, component, i);
                ans.push_back(component);
            }
        }

        // Print DFS components
        for (auto &comp : ans) {
            for (int node : comp) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DFS graph;
    int vertices = 5;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}
    };

    cout << "DFS Traversal (Adjacency List):\n";
    graph.Print_DFS_List(vertices, edges);

    return 0;
}
