#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i< s.size(); i++){
        char c = s[i];
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else{
            if(st.empty()){
                return false;
            }
            char top = st.top();
            if((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    string x = "()[]{}";
    cout<<isValid(x)<<endl;
    return 0;
}