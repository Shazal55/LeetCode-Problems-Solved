#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findKthLargest(vector<int>& nums, int k) { // O(nlog(n))
    int n = nums.size();
    sort(nums.begin(),nums.end());
    return nums[n-k];
}
int findKthLargest1(vector<int>& nums, int k) { // O(n)
    int largest = 0;
    int n = nums.size();
    int max = 0;
    for(int i = 0; i<n; i++){
        if(nums[i]> nums[max])
            max = i;
    }
    nums[max] = INT32_MIN;
    max = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] > nums[max])
        max = i;
    }
    return nums[max];
}

int findKthLargest2(vector<int>& nums, int k) { // O(n) CountSort Method
    vector<int> count(20001,0);
    for(int num : nums){
        count[num + 10000]++;
    }
    for(int i = 20000; i>=0; i--){
        k -= count[i];
        if(k <= 0){
            return i - 10000;
        }
    }
    return -1;
}

int main(){
    int element = 2;
    vector<int> vec = {3,2,1,5,6,4};
    int largest = findKthLargest2(vec,element);
    cout<<largest<<endl;
    return 0;
}
//Output : 5