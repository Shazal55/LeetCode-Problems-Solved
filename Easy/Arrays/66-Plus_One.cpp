#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for(int i = n-1; i>=0; i--){
        if( digits[i] < 9 ){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(),1);
    return digits;
}
int main(){
    vector<int> v = {1,2,9};
    vector<int> ans = plusOne(v);
    for(int val : ans){
        cout<<val<<" ";
    }
    return 0;
}
//Output : {1,3,0}