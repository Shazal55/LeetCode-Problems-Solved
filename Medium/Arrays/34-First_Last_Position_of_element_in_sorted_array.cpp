#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1,-1};
    int st = 0;
    int end = nums.size()-1;
    int left = -1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(nums[mid] == target){
            left = mid;
            end = mid-1;
        }
        else if(nums[mid] < target){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    if(left == -1){
        return result;
    }

    st = 0;
    end = nums.size()-1;
    int right = -1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(nums[mid] == target){
            right = mid;
            st = mid+1;
        }
        else if(nums[mid] < target){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    result[0] = left;
    result[1] = right;
    return result;   
}
int main(){
    vector<int> vec = {5,7,7,8,8,10};
    int target = 7;
    vector<int> result = searchRange(vec,target);
    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;
    return 0;
}