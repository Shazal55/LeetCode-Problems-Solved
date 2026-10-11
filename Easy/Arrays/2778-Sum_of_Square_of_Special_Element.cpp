#include <iostream>
#include <vector>
using namespace std;
int sumOfSquares(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for(int i = 1; i<=n; i++){
        if(n % i == 0){
            ans += nums[i-1] * nums[i-1];
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {2,7,1,19,18,3};
    cout<<"Sum of Squares : "<<sumOfSquares(arr)<<endl;
    return 0;
}
//Sum of Squares : 63