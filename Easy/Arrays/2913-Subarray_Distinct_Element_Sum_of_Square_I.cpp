#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int sumCounts(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for(int i = 0; i<n; i++){
        unordered_set<int> s;
        for(int j = i; j<n; j++){
            s.insert(nums[j]);
            int distinct = s.size();
            ans += distinct*distinct;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {1,2,1};
    cout<<sumCounts(vec)<<endl;
    return 0;
}
//15