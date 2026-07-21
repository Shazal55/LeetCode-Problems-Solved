#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<vector<int>> s;
void combsum(vector<int> &candidate,vector<int> &comb, vector<vector<int>> &ans,int idx,int target){
    if(idx == candidate.size() || target<0){
        return;
    }
    if(target == 0){
        if(s.find(comb) == s.end()){
            ans.push_back(comb);
            s.insert(comb);
        }
        return;
    }
    comb.push_back(candidate[idx]);
    combsum(candidate,comb,ans,idx+1,target-candidate[idx]);
    combsum(candidate,comb,ans,idx,target-candidate[idx]);
    comb.pop_back();
    combsum(candidate,comb,ans,idx+1,target);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    combsum(candidates,comb,ans,0,target);
    return ans;
}
int main(){
    vector<int> arr = {2,3,6,7};
    int target = 8;
    vector<vector<int>> ans = combinationSum(arr,target);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Output : 
2 3 3 
2 6 
2 2 2 2 
*/
