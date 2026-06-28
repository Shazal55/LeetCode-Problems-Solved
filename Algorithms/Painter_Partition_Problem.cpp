#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> arr,int n, int m, int maxUnits){
    int painter = 1;
    int units = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > maxUnits){
            return false;
        }
        if(arr[i] + units <= maxUnits){
            units += arr[i];
        }
        else{
            painter++;
            units = arr[i];
        }
    }
    return painter > m? false : true;
}
int PainterPartition(vector<int> arr, int n ,int m){//)(nlogN)
    if(m>n){
        return -1;
    }
    int sum = 0;
    for(int val : arr){
        sum += val;
    }
    int st = 0;
    int end = sum;
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(arr,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {40,30,10,20};
    int n = 4,m = 2;
    cout<<PainterPartition(arr,n,m)<<endl;
}
//Output : 60
//Goal : Partition the boards among k painters (without splitting any board and keeping the boards assigned to each painter contiguous) such that the maximum time taken by any painter is minimized.