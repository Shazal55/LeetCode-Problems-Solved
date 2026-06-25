#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int k = 0;
    for(int j = 1; j<nums.size();j++){
        if(nums[j] != nums[k]){
            k++;
            nums[k] = nums[j];
        }
    }
    return k+1;
}
int main(){
    vector<int> vec = {1,1,2};
    cout<<removeDuplicates(vec)<<endl;
}