#include <iostream>
#include <vector>
using namespace std;
vector<int> PairSum(int *arr,int size,int target){//Brute Force(On^2)
    vector<int> vec;
    for(int st = 0; st < size; st++){
        for(int end = st+1; end < size; end++){
            if(arr[st] + arr[end] == target){
                vec.push_back(arr[st]);
                vec.push_back(arr[end]);
            }
        }
    }
    return vec;
}
vector<int> PairSum1(int arr[], int n, int targ){// Optimized Approach using two pointers(O(n) time complexity)
    vector<int> vec;
    int i = 0,j = n-1;
    while(i < j){
        int pairSum = arr[i]+arr[j];
        if(pairSum == targ){
            vec.push_back(arr[i]);
            vec.push_back(arr[j]);
            break;
        }
        else if(pairSum > targ){
            j--;
        }
        else{
            i++;
        }
    }
    return vec;
}
int main(){
    int size = 4;
    int target = 13;
    vector<int> vec;
    int arr[size] = {2,7,11,15};
    vec = PairSum1(arr,size,target);
    for(int val : vec){
        cout<<val<<",";
    }
    cout<<endl;
    return 0;
}