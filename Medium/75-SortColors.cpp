#include <iostream>
#include <vector>
using namespace std;
int sortColors(vector<int> &nums){//O(n^2)
    int n = nums.size();
    for(int i = 0; i <n-1; i++){
        for(int j = i+1; j<n; j++){
            if(nums[j] < nums[i]){
                swap(nums[j],nums[i]);
            }
        }
    }
}
int sortColors1(vector<int> &nums){ //O(n) Double Pass
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int val : nums){
        if(val == 0){
            count0++;
        }
        else if(val == 1){
            count1++;
        }
        else{
            count2++;
        }
    }
    int idx = 0;
    for(int i = 0; i<count0; i++){
        nums[idx] = 0;
        idx++;
    }
        for(int i = 0; i<count1; i++){
        nums[idx] = 1;
        idx++;
    }
        for(int i = 0; i<count2; i++){
        nums[idx] = 2;
        idx++;
    }
}
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