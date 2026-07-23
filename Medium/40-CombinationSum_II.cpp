#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
set<vector<int>> s;
void CombSum(vector<int>& candidates,vector<vector<int>> &ans,vector<int> comb,int idx, int target){//O(nlogn + n*2^n) = O(n*2^n)
    if(target == 0){
        if(s.find(comb) == s.end()){
            ans.push_back(comb);
            s.insert(comb);
        }
        return;
    }
    if(idx == candidates.size() || target <0){
        return;
    }
    for(int i = idx; i<candidates.size(); i++){
        if(i> idx && candidates[i] == candidates[i-1])
            continue;
        comb.push_back(candidates[i]);
        CombSum(candidates,ans,comb,i+1,target-candidates[i]);
        comb.pop_back();
    }
    
    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> comb;
    CombSum(candidates,ans,comb,0,target);
    return ans;
}
int main(){
    vector<int> arr = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(arr,target);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Output:
1 1 6 
1 2 5 
1 7 
2 6 
*/
