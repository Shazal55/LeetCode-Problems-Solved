#include <iostream>
#include <vector>
using namespace std;
void reverseString(vector<char>& s) {
    int st = 0;
    int end = s.size()-1;
    while(st < end){
        swap(s[st],s[end]);
        st++;
        end--;
    }
}
int main(){
    vector<char> vec = {'h','e','l','l','o'};
    reverseString(vec);
    for(char val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;

}