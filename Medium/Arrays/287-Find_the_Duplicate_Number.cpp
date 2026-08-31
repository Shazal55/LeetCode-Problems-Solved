#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int>& nums) {//TC: O(n), SC: O(1)
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];//+1
        fast = nums[nums[fast]];//+2
    }
    while(slow != fast);
    slow = nums[0];
    while(slow!= fast){
        slow = nums[slow];//+1
        fast = nums[fast];//+1
    }
    return slow;
}
int main(){
    vector<int> nums = {1,4,2,3,2};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}