#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis){
    vis[i] = true;
    for(int j = 0; j<adj[i].size(); j++){
        if(adj[i][j] && !vis[j]){
            dfs(j,adj,vis);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int numOfProvinces = 0;
    int n = isConnected.size();
    vector<bool> vis(n,false);
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(i,isConnected,vis);
            numOfProvinces++;
        }
    }
    return numOfProvinces;
}

int main(){
    vector<vector<int>> vec = {{1,1,0,0},{1,1,0,0},{0,0,1,1},{0,0,1,1}};
    cout<<"No. of Provinces in the graph : "<<findCircleNum(vec)<<endl;
    return 0;
}
//Output:- No. of Provinces in the graph : 2