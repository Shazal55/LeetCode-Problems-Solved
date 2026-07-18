#include <iostream>
#include <vector>
using namespace std;
void getSubset(vector<int> &nums, vector<int> &ans,int i,vector<vector<int>> &allSubset){//(n*2^n)
    if( i== nums.size()){
        allSubset.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    getSubset(nums,ans,i+1,allSubset);
    ans.pop_back();
    getSubset(nums,ans,i+1,allSubset);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubset;
    vector<int> ans;
    getSubset(nums,ans,0,allSubset);
    return allSubset;
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(int i = 0; i<ans.size();i++){
        for(int j =0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}