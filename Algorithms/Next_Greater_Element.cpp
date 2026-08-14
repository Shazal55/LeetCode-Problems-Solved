#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums){//TC : O(n), SC : O(n)
    stack<int> s;
    vector<int> ans(nums.size(),0);
    for(int i = nums.size()-1; i>= 0; i--){
        while(s.size()>0 && s.top() <= nums[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(nums[i]);
    }
    return ans;
}
int main(){
    vector<int> vec = {6,8,0,1,3};
    vector<int> ans = nextGreaterElement(vec);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}