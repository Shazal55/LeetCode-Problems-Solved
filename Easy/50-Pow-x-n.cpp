#include <iostream>
using namespace std;
double power(double x,int n){//using for loop O(n)
    double power = 1;
    if(n < 0){
        x = 1/x;
        n = -n;
    }
    for(int i = 0;i<n;i++){
        power *= x;
    }
    return power;
}
double power1(double x, int n){ // Recursive approach O(n)
    if(n == 0){
        return 1;
    }
    if( n < 0){
        return 1/power(x,-n);
    }
    return x * power(x,n-1);
}
double power2(double x, int n){ //Binary exponentiation O(log(n))
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && n%2 == 0) return 1.0;
    if(x == -1 && n%2 != 0) return -1.0;
    long binform = n;
    double ans = 1;
    if(n < 0){
        x = 1/x;
        binform = -binform;
    }
    while(binform > 0){
        if(binform % 2 == 1){
            ans *= x;
        }
        x *= x;
        binform/= 2;
    }
    return ans;

}
int main(){
    double n;
    int p;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Enter the power : ";
    cin>>p;
    cout<<n<<"^"<<p<<" = "<<power2(n,p);
}