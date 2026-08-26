#include <iostream>
#include <vector>
using namespace std;
int thirdMax(vector<int>& nums) {
    long long first= INT64_MIN;
    long long second= INT64_MIN ;
    long long third = INT64_MIN;
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] == first || nums[i] == second || nums[i] == third){
            continue;
        }
        if(nums[i]>first){
            third = second;
            second = first;
            first =nums[i];
            
            
        }
        else if(nums[i] > second){
            third = second;
            second =  nums[i];
        }
        else if(nums[i] > third){
            third = nums[i];
        }
    }
    if(third == INT64_MIN){
        third = first;
    }
    return third;
}

int main(){
    vector<int> nums = {1,2,3,4};
    cout<<thirdMax(nums)<<endl;
    return 0;
}