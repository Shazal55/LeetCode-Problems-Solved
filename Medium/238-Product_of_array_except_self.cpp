#include<iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums){//Brute force approach with Time Complexity of O(n^2)
    vector<int> ans;
    for(int i =0; i < nums.size();i++){
        long product = 1;
        for(int j = 0; j < nums.size(); j++){
            if(i != j){
                product *= nums[j];
            }
        }
        ans.push_back(product);
    }
    return ans;
}
vector<int> productExceptSelf1(vector<int> &nums){//Optimized approach with Time Complexity O(n) and Space Complexity O(n)
    int n = static_cast<int>(nums.size());
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    vector<int> ans(n,1);
    for(int i = 1; i< n; i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }
    for(int i = n-2; i >=0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }
    for(int i = 0; i<n; i++){
        ans[i] = prefix[i]*suffix[i];
    }
    return ans;
}
vector<int> productExceptSelf2(vector<int>& nums){// More optimized, Time Complexity O(n) and Space Complexity O(1)
    int n = nums.size();
    vector<int> ans(n,1);
    int suffix = 1;
    for(int i = 1; i < n; i++){
        ans[i] = nums[i-1] * ans[i-1];
    }
    for(int i = n-2; i >=0; i--){
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }
    return ans;
}
int main(){
    vector<int> nums = {-1,1,0,2,-2};
    vector<int> ans = productExceptSelf2(nums);
    for(int val : ans){
        cout<<val<<" ";
    }
}