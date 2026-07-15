#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//Brute force Approach
vector<int> twoSum(vector<int>& nums, int target) {// O(n^2)
    vector<int> index;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){ 
        for(int j = i+1; j < nums.size(); j++){
            sum = nums[i] + nums[j];
            if(sum == target){
                index.push_back(i);
                index.push_back(j);
                return index;
            }
        }
    }
    return index;
}
//Better Appraoch
vector<int> twoSum1(vector<int>& nums, int target){//TC : O(nlogn)
    vector<int> index;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int st = 0;
    int end = n-1;
    while(st < end){
        int sum = nums[st]+nums[end];
        if(sum == target){
            index.push_back(st);
            index.push_back(end);
            break;
        }
        else if(sum > target){
            end--;
        }
        else{
            st++;
        }
    }
    return index;
}
//Optimized Approach
vector<int> twoSum2(vector<int>& nums, int target){//O(n)
    unordered_map<int,int> m;
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        int first = nums[i];
        int second = target - first;
        if(m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }
        m[first] = i;
    }
    return ans;
}
int main(){
    vector<int> vec = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum2(vec,target);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
}