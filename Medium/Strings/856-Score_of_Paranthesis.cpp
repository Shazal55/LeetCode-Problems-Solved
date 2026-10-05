#include <iostream>
#include <stack>
using namespace std;
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(0);
            }
            else {
                int tp = st.top();
                st.pop();
                int value;
                if(tp == 0){
                    value = 1;
                }
                else{
                    value = 2 * tp;
                }
                st.top()+= value;
            }
        }
        return st.top();
    }
