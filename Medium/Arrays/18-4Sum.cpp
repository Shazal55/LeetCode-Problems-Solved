#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            for(int j = i+1; j<n; ){
                int p = j+1;
                int q = n-1;
                while(p<q){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                    if(sum > target){
                        q--;
                }
                else if(sum < target){
                        p++;
                }
                else{
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    p++;
                    q--;
                    while(p<q && nums[p] == nums[p-1]) p++;
                    while(p < q && nums[q] == nums[q+1]) q--;
                }
            }
            j++;
            while(j<n && nums[j] == nums[j-1]) 
                j++;
        }
    }
    return ans;
}


int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums,target);
    int n = ans.size();
    int m = ans[0].size();
    for(int i = 0; i<n; i++){
        cout<<"{";
        for(int j = 0 ; j<m; j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"}"<<endl;
    }
    return 0;
}
/*Output:
    {-2,-1,1,2,}
    {-2,0,0,2,}
    {-1,0,0,1,}
*/