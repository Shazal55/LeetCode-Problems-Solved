#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {//TC: O(n), SC:O(1)
    int n = s.length();
    int m = t.length();
    if(n!= m){
        return false;
    }
    vector<int> freqS(26,0);
    vector<int> freqT(26,0);
    for(int i = 0; i<n; i++){
        freqS[s[i]-'a']++;
    }
    for(int j = 0; j<m; j++){
        freqT[t[j] - 'a']++;
    }
    for(int i = 0; i<26; i++){
        if(freqS[i] != freqT[i]){
            return false;
        }
    }
    return true;
}
bool isAnagram1(string s, string t) {
    if(s.length()!= t.length()){
        return false;
    }
    vector<int> freq(26,0);
    for(int i = 0; i<s.length(); i++){
        freq[s[i]-'a']++;
        freq[t[i] - 'a']--;
    }
    for(int val : freq){
        if(val != 0){
            return false;
        }
    }
    return true;
}
int main(){
    string s = "aana";
    string t = "naaa";
    if(isAnagram1){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
