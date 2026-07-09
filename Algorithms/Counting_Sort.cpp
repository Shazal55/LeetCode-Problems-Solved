#include <iostream>
#include <vector>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
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
    vector<int> vec = {3,2,1,5,6,4};
    int k = 2;
    cout<<findKthLargest(vec,k)<<endl;
    return 0;
}
//-10000 <= nums[i] <= 10000