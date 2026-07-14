#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_set<int> s;
    vector<int> ans;
    int n = grid.size();
    int m = grid[0].size();
    int a;
    int actualSum = 0;
    for(int i= 0; i<n; i++){
        for(int j = 0; j<m; j++){
            actualSum += grid[i][j];
            if(s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    int expectedSum = (n*m) * (n*m + 1)/2;
    int b = expectedSum - actualSum + a;
    ans.push_back(b);
    return ans;
}
int main(){
    vector<vector<int>> vec = {{1,3},{2,2}};
    vector<int> ans = findMissingAndRepeatedValues(vec);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}