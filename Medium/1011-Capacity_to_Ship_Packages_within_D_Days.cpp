#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isValid(vector<int>& weights, int days,int n, int maxAllowed){
    int daysUsed = 1;
    int weight = 0;
    for(int i = 0; i<n; i++){
        if(weights[i] > maxAllowed){
            return false;
        }
        if(weights[i] + weight <= maxAllowed){
            weight += weights[i];
        }
        else{
            daysUsed++;
            weight = weights[i];
        }
    }
    return daysUsed <= days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int m = days;
    int st = *max_element(weights.begin(), weights.end());
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += weights[i];
    }
    int end = sum;
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(weights, m, n, mid)){
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
    vector<int> vec = {3,2,2,4,1,4};
    int days = 3;
    cout<<shipWithinDays(vec,days)<<endl;
    return 0;
}
//Output : 6