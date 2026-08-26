#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int left = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if(nums[i] != 0){
            swap(nums[left],nums[i]);
            left++;
        }
    }
    for(int val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    return 0;
}