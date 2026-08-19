#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//Brute Force Approach
vector<int> maxSlidingWindow(vector<int>& nums, int k) {//TC : O(n*k)
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i<=n-k; i++){
        int maxElement = INT32_MIN;
        for(int j = i; j < i+k; j++){
            maxElement = max(nums[j],maxElement);
        }
        ans.push_back(maxElement);
    }
    return ans;
}

//Optimized Appraoch
vector<int> maxSlidingWindow1(vector<int>& nums, int k) {//TC : O(n), SC : O(n)
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;
    for(int i = 0; i<k; i++){
        while(dq.size()>0 &&  nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i = k; i<n; i++){
        ans.push_back(nums[dq.front()]);
        while(dq.size()>0 && dq.front()<= i-k){
            dq.pop_front();
        }
        while(dq.size()>0 &&  nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    return ans;
}
int main(){
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow1(vec,k);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//Output : 3 3 5 5 6 7