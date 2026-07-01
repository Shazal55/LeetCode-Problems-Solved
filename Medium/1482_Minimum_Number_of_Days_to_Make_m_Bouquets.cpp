#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(vector<int> arr, int m,int k, int mid){
    int bouquets = 0;
    int consecutive = 0;
    for(int days : arr){
        if(days <= mid){
            consecutive++;
        }
        else{
            bouquets += consecutive/k;
            consecutive = 0;
        }
    }
    bouquets += consecutive/k;
    return bouquets >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    if(m*k > bloomDay.size()){
        return -1;
    }
    int n = bloomDay.size();
    int st = *min_element(bloomDay.begin(),bloomDay.end());
    int end = *max_element(bloomDay.begin(),bloomDay.end());
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(bloomDay,m,k,mid)){
            ans = mid;
            end = mid -1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout<<minDays(vec,m,k)<<endl;
    return 0;
}