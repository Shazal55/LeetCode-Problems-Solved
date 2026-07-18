#include <iostream>
using namespace std;
bool isPowerOfFour(int n) {//O(logn base 4)
    if(n == 1){
        return true;
    }
    if(n <= 0 || n%4 != 0){
        return false;
    }
    return isPowerOfFour(n/4);
}
bool isPowerOfFour1(int n) {
    if(n <= 0 ){
        return false;
    }
    while(n%4 == 0){
        n = n/4;
    }
    return n == 1;
}
int main(){
    int n = 64;
    if(isPowerOfFour1){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}