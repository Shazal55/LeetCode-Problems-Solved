#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {//TC: O(n^2)
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(nums[i]>nums[j]){
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {//TC : O(nlogn)
    vector<int> temp = nums;
    sort(temp.begin(),temp.end());
    unordered_map<int,int> mp;
    for(int i =0 ; i<temp.size(); i++){
        if(mp.find(temp[i]) == mp.end()){
            mp[temp[i]] = i;
        }
    }
    vector<int> ans;
    for(int val: nums){
        ans.push_back(mp[val]);
    }
    return ans;
}
int main(){
    vector<int> vec = {8,1,2,2,3};
    vector<int> ans = smallerNumbersThanCurrent1(vec);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//Output : 4 0 1 1 3 