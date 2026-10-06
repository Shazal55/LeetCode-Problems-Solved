#include <iostream>
using namespace std;
int minAddToMakeValid(string s) {
    int left = 0;
    int ans = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            left++;
        }
        else{
            if(left > 0){
                left--;
            }
            else{
                ans++;
            }
        }
    }
    return ans+left;
}

int main(){
    string s = "()))((";
    cout<<minAddToMakeValid(s);
    return 0;
}