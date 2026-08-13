#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> previousSmaller(vector<int> &nums){
    vector<int> ans(nums.size(),0);
    stack<int> s;
    for(int i = 0; i<nums.size(); i++){
        while(s.size()>0 && s.top() >= nums[i]){
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
    vector<int> vec = {3,1,0,8,6};
    vector<int> ans = previousSmaller(vec);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}