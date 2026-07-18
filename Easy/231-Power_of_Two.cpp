#include <iostream>
using namespace std;
bool isPowerOfTwo(int n) {//O(logn)
    if(n <= 0){
        return false;
    }
    while(n%2 == 0){
        n = n/2;
    }
    return n==1;
}
bool isPowerOfTwo1(int n){
    if(n == 1){
        return true;
    }
    if(n <= 0 || n%2 != 0){
        return false;
    }
    return isPowerOfTwo1(n/2);
}
int main(){
    int n = 16;
    if(isPowerOfTwo1){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}