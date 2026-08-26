#include <iostream>
using namespace std;
bool IsPerfectSquare(int num) {
    for(long i = 1;  i*i<=num; i++){//O(√n)
        if(i * i == num){
            return true;
        }
    }
    return false;
}

bool isPerfectSquare(int num) {//O(log(n))
    int st = 1;
    int end = num;
    long square = 1;
    while(st<= end){
        long mid = st + (end - st)/2;
        square = mid*mid;
        if(square == num){
            return true;
        }
        else if( square<num){
            st = mid+1;
        }
        else{
            end = mid - 1;
        }
    }   
    return false;
}
int main(){
    int n = 16;
    if(isPerfectSquare(n)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}