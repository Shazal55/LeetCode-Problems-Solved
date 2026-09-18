#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recpath,vector<vector<int>>& edge ){
        vis[src] = true;
        recpath[src] = true;

        for(int i = 0; i<edge.size(); i++){
            int v = edge[i][0];
            int u = edge[i][1];

            if(u == src){
                if(!vis[v]){
                    if(isCycleDFS(v,vis,recpath,edge)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src] = false;
        return false;
    }

    void topo(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& edge){
        vis[src] = true;
        for(int i = 0; i<edge.size(); i++){
            int v = edge[i][0];
            int u = edge[i][1];

            if(u == src){
                if(!vis[v]){
                    topo(v,vis,s,edge);
                }
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        vector<int> ans;
        stack<int> s;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recpath,edge)){
                    return ans;
                }
            }
        }
        vis.assign(n,false);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                topo(i,vis,s,edge);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};