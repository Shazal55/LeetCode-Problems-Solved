#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(vector<int> arr, int m , int penality){
    int operation = 0;
    for(int balls : arr){
        operation += (balls - 1)/penality;
        if(operation > m){
            return false;
        }
    }
    return true;
}
int minimumSize(vector<int>& nums, int maxOperations) {
    int st =1;
    int end = *max_element(nums.begin(),nums.end());
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(nums,maxOperations,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {2,4,8,2};
    int maxOperations = 4;
    cout<<minimumSize(vec,maxOperations)<<endl;
    return 0;
}
//Output : 2