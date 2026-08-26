#include <iostream>
#include <vector>
using namespace std;
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {//TC: O(n+m), SC : O(n+m)
    string str1 = "";
    string str2  = "";
    for(string val : word1){
        str1 += val;
    }
    for(string val : word2){
        str2 += val;
    }
    return str1 == str2;
}

bool arrayStringsAreEqual1(vector<string>& word1, vector<string>& word2){//TC: O(n+m), SC : O(1)
    int i = 0, j = 0;
    int k = 0, l = 0;
    while(i<word1.size() && k< word2.size()){
        if(word1[i][j] != word2[k][l]){
            return false;
        }
        j++;
        l++;
        if(j == word1[i].size()){
            i++;
            j = 0;
        }
        if(l == word2[k].size()){
            k++;
            l = 0;
        }
    }
    return i == word1.size() && k == word2.size();
}
int main(){
    vector<string> word1 = {"ab","c"};
    vector<string> word2 = {"a","bc"};
    if(arrayStringsAreEqual1(word1,word2)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}