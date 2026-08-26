#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int numJewelsInStones(string jewels, string stones) {//TC: O(n^m), SC: O(1)
    int count =0;
    int m =stones.length();
    for(char val: jewels){
        for(int i = 0; i<m ; i++){
            if(val == stones[i]){
                count++;
            }
        }
    }
    return count;
}

int numJewelsInStones1(string jewels, string stones) {//TC: O(n+m), SC: O(n)
    unordered_set<char> s(jewels.begin(),jewels.end());
    int count = 0;
    for(char val : stones){
        if(s.find(val) != s.end()){
            count++;
        }
    }
    return count;
}
int main(){
    string jewels = "aA";
    string stones = "aAAbbbb";
    cout<<numJewelsInStones1(jewels,stones)<<endl;
    return 0;
}