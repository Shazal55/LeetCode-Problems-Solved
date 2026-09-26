#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for(int i = 1; i<strs.size(); i++){
        int len = min(prefix.size(), strs[i].size());
        if(len == 0){
            return "";
        }
        for(int j = 0; j< len; j++){
            if(strs[i][j] != prefix[j]){
                prefix = prefix.substr(0,j);
                break;
            }
            if(j == len -1){
                prefix = prefix.substr(0,len);
            }
        }
    }
    return prefix;
}
int main(){
    vector<string> strs = {"flower","flow","flight"};
    string ans = longestCommonPrefix(strs);
    cout<<ans<<endl;
    return 0;
}
//Output : "fl"