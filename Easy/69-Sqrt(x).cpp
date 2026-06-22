#include <iostream>
using namespace std;
int sqrt(int x){
    if(x < 0) return 0;
    int left = 0;
    int right = x;
    int ans = 0;
    while(left <= right){
        long mid = left + (right - left)/2;
        if(mid * mid == x)
            return mid;
        else if (mid * mid < x){
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid -1;
    }
    return ans;
}
int main(){
    int x = 256;
    cout<<sqrt(x);
}