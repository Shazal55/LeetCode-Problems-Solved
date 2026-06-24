#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int st = 0;
    int end = nums.size()-1;
    int mid = 0;
    while(st <= end){        
        mid = st + (end - st)/2;            
        if(target == nums[mid]){
            return mid;
        }
        if(nums[st] <= nums[mid]){//  left half sorted
            if(nums[st] <= target && target <= nums[mid]){
                end = mid-1;
            } 
            else{
                st = mid+1;
            }
        }
        else {// Right half sorted
            if(nums[mid]<= target && target <= nums[end]){
                st = mid+1;
            }
        else{
                end = mid - 1;
            }
        }
    }
    return -1;
    }
int main(){
    vector<int> vec = {7,8,9,1,2,3,4,5,6};
    int target = 6;
    cout<<search(vec,target)<<endl;
    return 0;
}