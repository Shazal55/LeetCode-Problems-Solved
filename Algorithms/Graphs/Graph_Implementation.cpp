#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Graph{
private:
    int V;
    list<int> *arr;
public:
    Graph(int v){
        this->V = v;
        arr = new list<int>[V];
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
        arr[v].push_back(u);

    }
    void addEdge_directed(int u , int v){
        arr[u].push_back(v);
    }
    void printAdjacencyList(){
        for(int i = 0; i<V; i++){
            cout<<i <<" : ";
            for(int val : arr[i]){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    //Breadth First Search Traversal
    void BFSTraversal(){ //O(V+E)
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0] = true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(int v : arr[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
    // Depth First Search Traversal
    void DFShelper(int u, vector<bool> &vis){
        cout<<u<<" ";
        vis[u] = true;
        for(int v : arr[u]){
            if(!vis[v]){
                DFShelper(v,vis);
            }
        }
    }
    void DFSTraversal(){ //O(V+E)
        vector<bool> vis(V,false);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                DFShelper(i,vis);
            }
        }
        cout<<endl;
    }
    // Cyclle detection for undirected graph using DFS
    bool isCycle(int src, int parent, vector<bool> &vis){
        vis[src] = true;
        list<int> neighbours = arr[src];
        for(int v : neighbours){
            if(!vis[v]){
                if(isCycle(v,src,vis)){
                    return true;
                }
            }
            else if(v != parent){
                return true;
            }
        }
        return false;
    }
    bool CycleDetection_DFS(){ //O(V+E)
        vector<bool> vis(V,false);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i,-1,vis)){
                    return true;
                }
            }
        } 
        return false;
    }
    //Cycle Detection for undirected graph using BFS
    bool isCycle_BFS_helper(int src, vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = true;
        while(q.size() > 0){
            pair<int,int> current = q.front();
            q.pop();
            int u = current.first;
            int parent = current.second;
            for(int v : arr[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push({v,u});
                }
                else if( v != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle_BFS(){ //For disconnected Graphs, O(V+E)
        vector<bool> vis(V,false);
        for(int i= 0; i<V; i++){
            if(!vis[i]){
                if(isCycle_BFS_helper(i,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    //Cycle detection for directed graph using dfs
    bool isCycle_Directed_DFS_helper(int curr, vector<bool>&vis, vector<bool> &recPath){
        vis[curr] = true;
        recPath[curr] = true;

        for(int v : arr[curr]){
            if(!vis[v]){
                if(isCycle_Directed_DFS_helper(v,vis,recPath)){
                    return true;
                }
            }
            else if( recPath[v]){
                return true;
            }
            
        }
        recPath[curr] = false;
        return false;
    }
    bool isCycle_Directed_DFS(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle_Directed_DFS_helper(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }

    //Topological sorting
    void helper1(int curr, vector<int> &vis, stack<int> &s){
        vis[curr] = true;
        for(int val : arr[curr]){
            if(!vis[val]){
                helper1(val,vis,s);
            }
        }
        s.push(curr);
    }
    void topologicalSorting(){ //O(V+E)
        vector<int> vis(V,false);
        stack<int> s;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                helper1(i,vis,s);
            }
        }
        while(!s.empty()){
            cout << s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};
int main(){

    Graph g(6);
    g.addEdge_directed(3,1);
    g.addEdge_directed(2,3);
    g.addEdge_directed(4,0);
    g.addEdge_directed(4,1);
    g.addEdge_directed(5,0);
    g.addEdge_directed(5,3);
    

    g.topologicalSorting();
    return 0;

}