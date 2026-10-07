#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph{
public:
    vector<vector<int>> adj;
    int V;
    Graph(int v){
        this->V = v;
        adj.resize(v);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    void topoSort(int curr, vector<bool> &vis, stack<int> &s){
        vis[curr] = true;
        for(int val : adj[curr]){
            if(!vis[val]){
                topoSort(val,vis,s);
            }
        }
        s.push(curr);
    }

    void dfs(int curr, vector<bool> &vis, vector<vector<int>> transpose){
        vis[curr] = true;
        cout<<curr<<" ";
        for(int val : transpose[curr]){
            if(!vis[val]){
                dfs(val,vis,transpose);
            }
        }
    }
    //This algorithm is used to find the strongly connected components in graphs
    void kosaraju(){ // O(V+E)
        //step 1 -- topological sort
        stack<int> s;
        vector<bool> vis(V,false);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                topoSort(i,vis,s);
            }
        }
        // step 2 -- Transpose of graph
        vector<vector<int>> transpose(V);
        for(int u = 0; u<V; u++){
            vis[u] = false;
            for(int v : adj[u]){
                transpose[v].push_back(u);
            }
        }
        //Step 3 -- DFS on Transpose
        while(s.size() > 0){
            int curr = s.top();
            s.pop();
            if(!vis[curr]){
                dfs(curr,vis,transpose);
                cout<<endl;
            }
        }
    }
};

int main(){
    Graph graph(5);

    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,0);
    graph.addEdge(2,1);
    graph.addEdge(3,4);

    graph.kosaraju();
    return 0;
}
//Output : 
// 0 1 2 
// 3 
// 4 