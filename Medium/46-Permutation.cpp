#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void getParams(vector<int> &nums, vector<vector<int>> &ans, int idx){//TC: O(n!*n), SC: O(n!)
    if(idx == nums.size()){
        ans.push_back({nums});
        return;
    }
    for(int i = idx; i<nums.size();i++){
        swap(nums[idx],nums[i]);
        getParams(nums,ans,idx+1);
        swap(nums[idx],nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    getParams(nums,ans,0);
    return ans;
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(int i = 0; i<ans.size();i++){
        for(int j =0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Output: 
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2 
*/