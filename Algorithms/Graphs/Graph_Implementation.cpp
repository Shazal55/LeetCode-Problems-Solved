#include <iostream>
#include <list>
#include <vector>
#include <queue>
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
        int src = 0;
        vector<bool> vis(V,false);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                DFShelper(i,vis);
            }
        }
        
        cout<<endl;
    }
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
};
int main(){
    vector<bool> vis();
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    // g.printAdjacencyList();
    // cout<<"Breadth First Search Traversal :- ";
    // g.BFSTraversal();
    // cout<<"Depth First Search Traversal :- ";
    // g.DFSTraversal();

    cout << g.CycleDetection_DFS()<<endl;
    return 0;

}
/*
Output:- 
0 : 1 
1 : 0 2 3 
2 : 1 3 4 
3 : 1 2 
4 : 2
Breadth First Search Traversal :- 0 1 2 3 4 
Depth First Search Traversal :- 0 1 2 4 3 
1
*/