#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maximumWealth(vector<vector<int>>& accounts) {
    vector<int> vec;
    int n = accounts.size();
    int m = accounts[0].size();
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = 0; j<m; j++){
            sum += accounts[i][j];
        }
        vec.push_back(sum);
    }
    int ans = *max_element(vec.begin(),vec.end());
    return ans;
}
int main(){
    vector<vector<int>> vec = {{1,2,3},{3,2,1}};
    cout<<maximumWealth(vec)<<endl;
    return 0;
}