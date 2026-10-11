#include <iostream>
#include <string>
using namespace std;

bool checkValidString(string s) {
    int high = 0;
    int low = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            high++;
            low++;
        }
        else if(s[i] == ')') {
            low = max(0,low-1);
            high--;
        }
        else{
            high++;
            low = max(0,low-1);
        }
        if(high < 0){
            return false;
        }
    }
    return low == 0;
}
int main(){
    string s = "(*))";
    cout<<checkValidString(s)<<endl;
    return 0;
}