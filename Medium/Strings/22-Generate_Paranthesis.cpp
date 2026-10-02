#include <iostream>
#include <string>
#include <vector>
using namespace std;

void backtrack(string curr, int open , int close, int n, vector<string> &ans){
    if(curr.size() == 2*n){
        ans.push_back(curr);
        return;
    }
    if(open < n){
        curr.push_back('(');
        backtrack(curr,open+1,close,n,ans);
        curr.pop_back();
    }
    if(close < open){
        curr.push_back(')');
        backtrack(curr,open,close+1,n,ans);
        curr.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack("",0,0,n,ans);
    return ans;
}

int main(){
    int n = 3;
    vector<string> vec = generateParenthesis(n);
    for(string val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//output : ((())) (()()) (())() ()(()) ()()() 