#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(vector<int> &piles, int h, int k){
    int hours = 0;
    for(int val : piles){
        hours += (val + k - 1)/k;
        if(hours >h){
            return false;
        }
    }
    return true;
    
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int st = 1;
    int end = *max_element(piles.begin(),piles.end());
    int ans = 0;
    while (st <= end){
        int mid = st + (end - st)/2;
        if(isValid(piles,h,mid)){
            end = mid - 1;
            ans = mid;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {30,11,23,4,20};
    int h = 5;
    cout<<"Bananas per hours : "<<minEatingSpeed(vec,h)<<endl;
    return 0;
}