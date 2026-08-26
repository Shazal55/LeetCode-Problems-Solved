#include <iostream>
#include <vector>
using namespace std;
vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n+1,0);
    for(int i: nums){
        freq[i]++;
    }
    vector<int> ans(2);
    for(int i = 1; i<=n; i++){
        if(freq[i] == 2){
            ans[0] = i;
        }
        else if(freq[i] == 0){
            ans[1] = i;
        }
    }
    return ans;
}
int main(){
    vector<int> nums ={1,2,2,4};
    vector<int> ans = findErrorNums(nums);
    cout<<ans[0] << " "<<ans[1]<<endl;
    return 0;
}