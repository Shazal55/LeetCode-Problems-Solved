#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size()-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}
int main(){
    int target = 4;
    vector<int> vec = {1,3,5,6};
    cout<<searchInsert(vec,target)<<endl;
    return 0;
}