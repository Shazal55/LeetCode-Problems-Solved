#include <iostream>
using namespace std;
string removeOuterParentheses(string s) { //O(n)
    int depth = 0;
    string ans;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            if(depth > 0)
                ans += s[i];
            depth++;
        }
        else{
            depth--;
            if(depth > 0){
                ans+= s[i];
            }
        }
    }
    return ans;
}
int main(){
    string s = "(()())(())";
    string ans = removeOuterParentheses(s);
    cout<<"String after Removing : "<<ans<<endl;
    return 0;
}
//Output : String after Removing : ()()()