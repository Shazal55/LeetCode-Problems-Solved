#include <iostream>
using namespace std;
int lengthOfLastWord(string s) {
    int end = s.length()-1;
    int count = 0;
    while( end >= 0 && s[end] == ' '){
        end--;
    }
    while(end >=0 && s[end]!= ' '){
        count++;
        end--;
    }
    return count;
}
int main(){
    string s = "Hello World";
    cout<<"Length of last word : "<<lengthOfLastWord(s)<<endl;
    return 0;
}