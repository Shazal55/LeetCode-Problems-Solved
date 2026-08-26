#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int>& nums) {//BruteForce O(n^2)
    int majority = nums.size()/2;
    for(int i = 0; i < nums.size(); i++){
        int count = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
        if(count > majority){
            return nums[i];
        }
    }
    return -1;
}
int majorityElement1(vector<int>& nums){ // Optimize Approach O(nlog(n))
    sort(nums.begin(),nums.end());
    int count = 0;
    int majority = nums.size()/2;
    int start = nums[0];
    for(int val : nums){
        if(val == start){
            count++;
        }
        else{
            start = val;
            count = 1;
        }
        if(count > majority){
            return start;
        }
    }
    return -1;
}
int MooresVoting(vector<int> &nums){//Boyer-Moore Voting Algorithm O(n)
    int count = 0;
    int ans = 0;
    for(int val : nums){
        if(count == 0){
            ans = val;
        }
        if(ans == val){
            count++;
        }
        else{
            count--;
        }
    }
    return ans;
}
int main(){
    vector<int> num = {2,2,1,1,1,2,2};
    cout<<"Majority element : "<<MooresVoting(num)<<endl;
    return 0;
}