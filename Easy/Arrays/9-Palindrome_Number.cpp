#include <iostream>
using namespace std;
bool isPalindrome(int x) {
    int original = x;
    long reversed = 0;
    while (original > 0){
        int digit = original % 10;
        reversed = digit + reversed*10;
        original = original / 10;
    }
    return reversed == x;
}
int main(){
    int x = 121;
    cout<<isPalindrome(x)<<endl;
    return 0;
}