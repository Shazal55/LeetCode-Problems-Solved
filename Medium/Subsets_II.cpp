#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void getSubset(vector<int> &nums,vector<int> ans, int i, vector<vector<int>> &allSubset){//O(n*2^n)
    if(i == nums.size()){
        allSubset.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    getSubset(nums,ans,i+1,allSubset);
    int idx = i+1;
    while(idx<nums.size() && nums[i] == nums[idx]){
        idx++;
    }
    ans.pop_back();
    getSubset(nums,ans,idx,allSubset);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> allSubset;
    vector<int> ans;
    getSubset(nums,ans,0,allSubset);
    return allSubset;
}
int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for(int i = 0; i<ans.size();i++){
        for(int j =0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}