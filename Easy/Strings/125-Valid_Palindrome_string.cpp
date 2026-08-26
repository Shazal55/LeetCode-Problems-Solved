#include <iostream>
using namespace std;
bool isAlphaNumeric(char ch){
    if((ch >= '0' && ch<='9') || (tolower(ch)>= 'a' && tolower(ch) <= 'z')){
        return true;
    }
    return false;
}
bool isPalindrome(string s) {// O(n)
    int st = 0;
    int end = s.length()-1;
    while (st < end){
        if(!isalnum(s[st])){//Built-in function
            st++;
            continue;
        }
        if(!isAlphaNumeric(s[end])){//Self made function
            end--;
            continue;
        }
        if(tolower(s[st]) != tolower(s[end])){
            return false;
        }
        st++;
        end--;
    }
    return true;
}
int main(){
    string s = "race a car";
    if(isPalindrome(s)){
        cout<<"The string is Palindrome"<<endl;
    }
    else{
        cout<<"This string is not a palindrome"<<endl;
    }
    return 0;
}