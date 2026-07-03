#include <iostream>
#include <vector>
using namespace std;
int KadaneAlgorithm(int *arr, int n){// Max SumArray Sum using Kadane's (Best Approach)
    int currentSum = 0;
    int maxSum = INT32_MIN;
    for(int i = 0; i < n; i++){
        currentSum += arr[i];
        maxSum = max(currentSum,maxSum);
        if(currentSum < 0){
            currentSum = 0;
        }
    }
    return maxSum;
}
int main(){
    int size = 9;
    int arr[size] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<"Maximum SubArray sum : "<<KadaneAlgorithm(arr,size);
    return 0;
}