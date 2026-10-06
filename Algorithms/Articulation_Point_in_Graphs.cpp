#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Graph{
public:
    int time;
    vector<int> dt,low;
    vector<vector<int>> adj;
    int V;
    Graph(int v){
        this->V = v;
        adj.resize(v);
    }
    void addEdge(int u , int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u , int parU,set<int> &critical_points){
        dt[u] = low[u] = ++time;
        int children = 0;
        for(int i = 0; i<adj[u].size();i++){
            int v = adj[u][i];
            if(dt[v] == -1){
                children++;
                dfs(v,u,critical_points);
                low[u] = min(low[u],low[v]);
                if(parU != -1 && low[v] >= dt[u]){
                    critical_points.insert(u);
                }
            }
            else if(v != parU){
                low[u] = min(low[u],dt[v]);
            }
        }
        if(parU == -1 && children >1){
            critical_points.insert(u);
        }
    }
    int articulation_point(){
        time = 0;
        dt.resize(V,-1);
        low.resize(V);
        set<int> critical_points;
        for(int i =0; i<V; i++){
            if(dt[i] == -1){
                dfs(i,-1,critical_points);
            }
        }
        for(auto val : critical_points){
            cout<<val<<" ";
        }
        cout<<endl;
        return critical_points.size();
    }
};

int main(){
    Graph graph(6);
    graph.addEdge(1,0);
    graph.addEdge(1,2);
    graph.addEdge(4,3);
    graph.addEdge(4,5);
    graph.addEdge(4,1);

    cout<<graph.articulation_point()<<endl;
    return 0;
}