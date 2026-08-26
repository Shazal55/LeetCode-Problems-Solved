#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    vector<int> num = nums;
    int ans = 0;
    for(int val : num){
        ans = ans ^ val;
    }
    return ans;
}
int main(){
    vector<int> vec = {4,1,2,1,2};
    cout<<singleNumber(vec)<<endl;
    return 0;
}