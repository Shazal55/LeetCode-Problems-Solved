//Input array is Sorted
#include <iostream>
#include <vector>
using namespace std;
// Prints all possible subarrays of the given array
// Time: O(n^3) | Space: O(1)
void PrintSubarrays(int arr[],int n){
    for(int st = 0; st < n; st++){
        for(int end = st; end < n; end++){
            for(int i = st; i <=end; i++){
                cout<<arr[i]<<",";
            }
            cout<<" ";
        }
        cout<<endl;
    }
}
// Returns the maximum subarray sum using brute force
// Tries all possible subarrays and tracks the maximum sum
// Time: O(n^2) | Space: O(1)
int MaxSubArraySum(int *arr,int n){// Max subarray sum (brute force - O(n^2))
    int maxElement = INT32_MIN;
    for(int st = 0; st < n; st++){
        int countSum = 0;
        for(int end = st; end < n; end++){
            countSum += arr[end];
            maxElement = max(countSum,maxElement);
        }
    }
    return maxElement;
}
// Returns the maximum subarray sum using Kadane's Algorithm
// Resets current sum to 0 whenever it goes negative
// Time: O(n) | Space: O(1)
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
// Prints the maximum subarray sum and the actual subarray elements
// Uses Kadane's approach while tracking elements in a vector
// Time: O(n) | Space: O(n)
void MaxSubArray(int arr[],int n){// Give the elements that give the maximum subarray sum
    int currentSum = 0;
    int maxSum = INT32_MIN;
    vector<int> vec;
    vector<int> vecbest;
    for(int i = 0; i < n; i++){
        vec.push_back(arr[i]);
        currentSum += arr[i];
        if(currentSum > maxSum){
            maxSum = currentSum;
            vecbest = vec;
        }
        if(currentSum < 0){
            currentSum = 0;
            vec.clear();
        }
    }
    cout<<"Max SubArray Sum : "<<maxSum<<endl;
    cout<<"SubArray with max sum : ";
    for(int val : vecbest){
        cout<<val<<",";
    }
    cout<<endl;
}
int main(){
    int size = 9;
    int arr[size] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    PrintSubarrays(arr,size);
    // cout<<"Maximum SubArray sum : "<<KadaneAlgorithm(arr,size);
    MaxSubArray(arr,size);
    return 0;
}
