#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int,int> mp;
    for(int i = nums2.size()-1; i>=0; i--){
        while(s.size()>0 && s.top()<= nums2[i]){
            s.pop();
        }
        if(s.empty()){
            mp[nums2[i]] = -1;
        }
        else{
            mp[nums2[i]] = s.top();
        }
        s.push(nums2[i]);
    }
    for(int i = 0; i<nums1.size(); i++){
        nums1[i] = mp[nums1[i]];
    }
    return nums1;
}
int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1,nums2);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}