#include <iostream>
#include <vector>
using namespace std;
int longestPalindrome(string s) {
    int n = s.length();
    int ans = 0;
    bool odd = false;
    vector<int> freq(128,0);
    for(int i = 0; i<n; i++){
        freq[s[i]]++;
    }        
    for(int i = 0; i<freq.size();i++){
        if(freq[i]%2 == 0){
            ans+= freq[i];
        }
        else{
            ans += freq[i]-1;
            odd = true;
        }
    }
    if(odd){
        ans++;
    }
    return ans;
}
int main(){
    string a = "abccccdd";
    cout<<longestPalindrome(a)<<endl;
    return 0;
}
//Output: 7