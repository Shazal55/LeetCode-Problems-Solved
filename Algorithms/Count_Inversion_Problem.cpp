/*
Inversion pairs : (arr[i],arr[j])
Conditions : 
    i<j
    arr[i]>arr[j]
*/
#include <iostream>
#include <vector>
using namespace std;
int countInversion(vector<int> & arr){//TC: O(n^2)
    int count = 0;
    for(int i = 0; i<arr.size(); i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}
int merge(vector<int> &arr,int st, int mid , int end){
    vector<int> temp;
    int invCount = 0;
    int i = st;
    int j = mid+1;
    while(i<=mid && j<= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invCount += mid - i +1;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx = 0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }
    return invCount;
}
int mergeSort(vector<int> &arr,int st, int end){
    if(st < end){
        int mid = st + (end-st)/2;
        int leftInvCount = mergeSort(arr,st,mid);
        int rightInvCount = mergeSort(arr,mid+1,end);
        int invCount = merge(arr,st,mid,end);
        return leftInvCount+rightInvCount+ invCount;
    }
    return 0;
}
int countInversion1(vector<int> &arr){//TC: O(nlogn) , SC : O(n)
    return mergeSort(arr,0,arr.size()-1);
}
int main(){
    vector<int> vec = {1,3,5,10,2,6,8,9};
    cout<<countInversion1(vec)<<endl;
    return 0;
}