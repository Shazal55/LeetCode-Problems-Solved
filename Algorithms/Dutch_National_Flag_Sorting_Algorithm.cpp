#include <iostream>
#include <vector>
using namespace std;
void sortColors2(vector<int> &nums){ // Dutch National Flag Algorithm TC: O(n) (Single Pass)
    int n = nums.size();
    int  mid = 0;
    int low = 0;
    int high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[high],nums[mid]);
            high--;
        }
    }
}
void PrintVector(vector<int> nums){
    for(int val : nums){
        cout<<val <<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> vec = {2,0,2,1,1,0};
    sortColors2(vec);
    PrintVector(vec);
    return 0;
}