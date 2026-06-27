#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            return nums[mid];
        
        if(mid % 2 == 0){
            if(nums[mid] == nums[mid-1]){
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] == nums[mid-1]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> vec = {3,3,7,7,10,11,11};
    cout<<singleNonDuplicate(vec)<<endl;
    return 0;
}