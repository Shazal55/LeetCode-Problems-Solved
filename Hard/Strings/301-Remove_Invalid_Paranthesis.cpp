#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

bool isValid(string s){
    int balance = 0;
    for(char ch : s){
        if(ch == '('){
            balance++;
        }
        else if(ch == ')'){
            balance--;
            if(balance < 0){
                return false;
            }
        }
    }
    return balance == 0;   
}
vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    queue<string> q;
    unordered_set<string> visited;
    q.push(s);
    visited.insert(s);
    bool found = false;
    while(q.size()>0){
        string curr = q.front();
        q.pop();
        if(isValid(curr)){
            ans.push_back(curr);
            found = true;
        }
        if(found){
            continue;
        }
        for(int i = 0; i<curr.length(); i++){
            if(curr[i] != '(' && curr[i] != ')'){
                continue;
            }
            string next = curr.substr(0,i) + curr.substr(i+1);
            if(visited.find(next) == visited.end()){
                visited.insert(next);
                q.push(next);
            }
        }
    }
    return ans;
}

int main(){
    string s = "()())()";
    vector<string> ans = removeInvalidParentheses(s);
    for(string val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//Output : (())() ()()() 