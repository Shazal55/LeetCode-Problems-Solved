#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,0);
    stack<int> s;
    for(int i = 2*n -1 ; i>= 0; i--){
        while(s.size()>0 && nums[s.top()] <= nums[i%n]){
            s.pop();
        }
        ans[i%n] = s.empty() ? -1 : nums[s.top()];
        s.push(i%n); 
    }
    return ans;
}
int main(){
    vector<int> nums1 = {1,2,3,4,3};
    vector<int> ans = nextGreaterElements(nums1);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}