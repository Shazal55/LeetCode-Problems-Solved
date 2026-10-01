#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int manhattan_distance(vector<vector<int>> &points, int p1, int p2){
    return abs(points[p1][0] - points[p2][0]) + 
            abs(points[p1][1] - points[p2][1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> vis(n,false);
    int mstCost = 0;

    pq.push({0,0});

    while(pq.size() > 0){
        auto x = pq.top();
        int wt = x.first;
        int v = x.second;
        pq.pop();

        if(vis[v]){
            continue;
        }

        vis[v] = true;
        mstCost += wt;

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                int edgeWT = manhattan_distance(points,v,i);
                pq.push({edgeWT,i});
            }
        }
    }
    
    return mstCost;
}
