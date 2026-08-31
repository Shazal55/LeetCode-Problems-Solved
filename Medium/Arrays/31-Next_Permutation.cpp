#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {//TC : O(n) SC: O(1)
    //Step 1 : Find the pivot
    int n = nums.size();
    int pivot = -1;
    for(int i = n-2; i>= 0; i--){
        if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(nums.begin(),nums.end());
        return;
    }
    // Step 2: Find next largest element
    for(int i = n-1; i>pivot; i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i],nums[pivot]);
            break;
        }
    }
    //Step 3 : Reverse
    int i = pivot+1;
    int j = n-1;
    while(i<= j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }

}
int main(){
    vector<int> vec = {1,3,2};
    nextPermutation(vec);
    for(int val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}