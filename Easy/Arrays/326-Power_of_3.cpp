#include <iostream>
#include <cmath>
using namespace std;
bool isPowerOfThree(int n) {//O(logn base 3)
    if(n <= 0)
        return false;
    while(n%3 == 0){
        n = n/3;
    }
    return n == 1;
}

bool isPowerOfThree1(int n){
    if(n == 1){
        return true;
    }
    if(n%3 != 0 || n<= 0){
        return false;
    }
    return isPowerOfThree1(n/3);
}
bool isPowerOfThree2(int n) {
    return n > 0 && (int)pow(3,19) % n == 0;//Larget possible number for 3^n in signed integer is 3^19 = 1162261467
}
bool isPowerOfThree3(int n){
    if(n <= 0){
        return false;
    }
    double x = log10(n)/log10(3); 
    return x == floor(x);
}
int main(){
    int n = 30;
    if(isPowerOfThree(n)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}
