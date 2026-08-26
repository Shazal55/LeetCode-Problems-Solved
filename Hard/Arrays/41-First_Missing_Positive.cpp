#include <iostream>
#include <vector>
using namespace std;
int firstMissingPositive(vector<int>& nums) {//O(n) + O(n) = O(n)
    int n = nums.size();
    for(int i = 0; i<n; i++){
        while(nums[i]>=1 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for(int i = 0; i<n; i++){
        if(nums[i] != i+1){
            return i+1;
        }
    }
    return n+1;
}
int main(){
    vector<int> nums = {3,4,-1,1};
    cout<<firstMissingPositive(nums)<<endl;
    return 0;
}
//Output : 2