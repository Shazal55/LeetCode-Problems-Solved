//Assign C cows to N stalls such that the min difference between them is largest possible.
//Return Largest minimum distance
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(vector<int> &arr, int n, int c, int mid){
    sort(arr.begin(),arr.end());
    int cow = 1;
    int lastPosition = arr[0];
    for(int i=1 ; i<n; i++){
        if(arr[i] - lastPosition >= mid){
            cow++;
            lastPosition = arr[i];
        }
        if (cow == c){
            return true;
        }
    }
    return false;
}
int AgressiveCow(vector<int> &arr, int n , int c){//O(nlog(range))
    int st = 1;
    int end = arr.end()- arr.begin();
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(arr,n,c,mid)){
            ans = mid;
            st = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return ans;
}
int main(){
    int n = 5;
    int c = 3;
    vector<int> vec = {1,2,8,4,9};
    cout<<AgressiveCow(vec,n,c);
    return 0;
}
//Output : 3
