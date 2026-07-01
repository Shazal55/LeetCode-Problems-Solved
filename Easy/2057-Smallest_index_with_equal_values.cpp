#include <iostream>
#include <vector>
using namespace std;
int smallestEqual(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if( i % 10 == nums[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> vec = {4,3,2,1};
    cout<<smallestEqual(vec)<<endl;
    return 0;
}
//Output : 2