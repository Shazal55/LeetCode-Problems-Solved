#include <iostream>
using namespace std;
int GCD(int a,int b){//O(min(a,b))
    int gcd = 1;
    for(int i = 1; i<=min(a,b); i++){
        if(a%i==0 && b%i==0){
            gcd =i;
        }
    }
    return gcd;
}
int Euclid_GCD(int a, int b){//O(a*b)
    while(a>0 && b> 0){
        if(a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a == 0){
        return b;
    }
    return a;
}
int recursive_GCD(int a, int b){
    if(a == b){
        return a;
    }
    if(a>b){
        return recursive_GCD(a-b,b);
    }
    return recursive_GCD(a,b-a);
}
int LCM(int a, int b){
    int gcd = Euclid_GCD(a,b);
    return (a*b)/gcd;
}
int main(){
    int a = 20,b = 28;
    cout<<LCM(a,b)<<endl;
    return 0;
}