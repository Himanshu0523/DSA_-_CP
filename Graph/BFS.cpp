#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

// Breath First search (BFS)
//
//      0
//        \
//          1
//            \
//      4 ---- 2
//       \    /
//        \  /
//          3

// Starting from zer0
//    0  connect nodes 1
//    then travese 1 nodes , it's connected nodes 2
//    then travese 2 nodes , it's connected nodes 3 , 4
//    then travese 3 nodes , it's connected nodes 4  and
//    then travese 4 nodes ,

//  node , connected node , visited
// visited - track the nodes
// unordered_map<node , bool> and fifo functionality queue

    class BFS
    {

    public:
        unordered_map<int, list<int>> adjList;

        // it adjlist are are arrange i n sorted ordered;6

        unordered_map<int, list<int>> adjList_creation(vector<pair<int, int>> &edges)
        {
            for (int i = 0; i < edges.size(); i++)
            {
                int u = edges[i].first;
                int v = edges[i].second;

                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            return adjList;
        }


        void bfs(unordered_map<int , list<int> > &adjList , unordered_map <int , bool> &visited , vector<int> &ans , int node) {
            queue<int> q;
            q.push(node);
            visited[node] = 1 ;

            while(!q.empty()) {
                int frontnode = q.front();
                q.pop();

                // store frontNOde into ans;
                ans.push_back(frontnode);

                //Traverse all neighbour of frontNode
                for(auto i : adjList[frontnode]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        }

        void Bfs_Traversal(int vertex, vector<pair<int, int>> &edges)
        {
            int frontNode = 0; // they show graph which edges are present , current
            queue<int> current;

            unordered_map<int, list<int>> perpare_list = adjList_creation(edges);
            unordered_map<int, bool> visited;
            vector<int> ans;

            // traverse all component of a graph
            for (int i = 0; i < vertex; i++)
            {
                if(!visited[i]){
                    bfs(adjList , visited , ans , i);
                }
            }
        }

        void printAdj(unordered_map<int , list<int> > &adjList) {
            for(auto i : adjList){
                cout<< i.first <<" -> " ;
                for(auto j: i.second) {
                    cout << j << ", ";
                }
                cout<<endl;
            }
        }
    };


int main() {

    cout<<"hello ";
    return 0;
}