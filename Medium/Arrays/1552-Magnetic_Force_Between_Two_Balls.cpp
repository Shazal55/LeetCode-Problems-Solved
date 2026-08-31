#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(vector<int>& arr, int n, int m, int allowed){
    int ball = 1;
    int lastPosition = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i] - lastPosition >= allowed){
            ball++;
            lastPosition = arr[i];
        }
        if(ball == m){
            return true;
        }
    }
    return false;
}
int maxDistance(vector<int>& position, int m) {
    sort(position.begin(),position.end());
    int n = position.size();
    int st = 1;
    int end = position[n-1]-position[0];
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(position,n,m,mid)){
            ans = mid;
            st = mid+1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {1,2,3,4,7};
    int m = 3;
    cout<<"Maximum allowed distance : "<<maxDistance(vec,m)<<endl;
    return 0;
}
//Output : 3