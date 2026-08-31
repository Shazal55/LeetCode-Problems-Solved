#include <iostream>
using namespace std;
int reverse(int x) {
    long long reverse = 0;
    int a;
    while(x != 0){
        a = x%10;
        x = x / 10;
        reverse  = reverse*10 + a;
        if(reverse > INT32_MAX || reverse < INT32_MIN){
            return 0;
        }
    }
    return reverse;
}
int main(){
    int x = 123;
    cout<<reverse(x);
    return 0;
}