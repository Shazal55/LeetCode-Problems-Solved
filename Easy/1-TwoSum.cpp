#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
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
int main(){
    vector<int> vec = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(vec,target);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
}