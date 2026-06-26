#include <iostream>
#include <vector>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    int left = 0;
    int index = nums.size()-1;
    int right = nums.size()-1;
    while(left <= right){
        if(abs(nums[left])>abs(nums[right])){
            ans[index] = nums[left]*nums[left];
            index--;
            left++;
        }
        else{
            ans[index] = nums[right]*nums[right];
            index--;
            right--;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {-7,-3,2,3,11};
    vector<int> ans = sortedSquares(vec);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
}