#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        queue<int> q;
        unordered_map<int,int> m;
        for(int i = 0; i<n; i++){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }
            m[s[i]]++;
            while(q.size()>0 && m[s[q.front()]]>1){
                q.pop();
            }
        }
        if(q.empty()){
            return -1;
        }
        else{
            return q.front();
        }
    }
};
