#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
bool wordPattern(string pattern, string s) {
    unordered_map<char,string> charToWord;
    unordered_set<string> record;
    vector<string> words;
    stringstream ss(s);
    string word;
    while(ss >> word){
        words.push_back(word);
    }
    if(pattern.length() != words.size()){
        return false;
    }
    for(int i = 0; i<pattern.length(); i++){
        char ch = pattern[i];
        string word = words[i];
        if(charToWord.count(ch)){
            if(charToWord[ch] != word){
                return false;
            }
        }
        else{
            if(record.count(word)){
                return false;
            }
            charToWord[ch] = word;
            record.insert(word);
        }
    }
    return true;
}
int main(){
    string s = "abba";
    string b = "dog cat cat dog";
    if(wordPattern){
        cout<<"True";
    }
    else{
        cout<<"false";
    }
    cout<<endl;
    return 0;
}