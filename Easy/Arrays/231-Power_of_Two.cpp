#include <iostream>
#include <cmath>
using namespace std;
bool isPowerOfTwo(int n) {//O(logn base 2)
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
bool isPowerOfTwo2(int n){
    if(n <= 0){
        return false;
    }
    double x = log10(n)/log10(2); 
    return x == floor(x);
}
int main(){
    int n = 16;
    if(isPowerOfTwo2){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}