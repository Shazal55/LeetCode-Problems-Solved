#include <iostream>
using namespace std;
bool detectCapitalUse(string word) {
        int upper = 0;
        int length = word.length();
        for(char cap : word){
            if(isupper(cap)){
                upper++;
            }
        }
        if(upper == length || upper == 0 || (upper == 1 && isupper(word[0]))){
            return true;
        }
        else{
            return false;
        }
    }
int main(){
    string word = "USA";
    if(detectCapitalUse(word)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}