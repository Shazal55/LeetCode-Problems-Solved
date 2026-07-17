#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Brute Force
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//O(NlogN)---(N->n+m)
    for(int val : nums2){
        nums1.push_back(val);
    }
    int n = nums1.size();
    double ans = 0;
    sort(nums1.begin(),nums1.end());
    if(n%2 == 0){
        ans = (nums1[n/2 - 1] + nums1[n/2]) / 2.0;;
    }
    else{
        ans = nums1[n/2.0];
    }
    return ans;
}
//Optimal Appraoch
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//O(m+n)
    int m = nums1.size();
    int n = nums2.size();
    vector<int> merge;
    int i = 0,j=0;
    while(i<m && j<n){
        if(nums1[i]>nums2[j]){
            merge.push_back(nums2[j]);
            j++;
        }
        else if(nums1[i]<nums2[j]){
            merge.push_back(nums1[i]);
            i++;
        }
        else{
            merge.push_back(nums1[i]);
            merge.push_back(nums2[j]);
            i++;
            j++;
        }
    }
    while(i<m){
        merge.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        merge.push_back(nums2[j]);
        j++;
    }
    int x = merge.size();
    if(x%2 != 0){
        return merge[x/2.0];
    }
    else{
        return (merge[x/2 -1] + merge[x/2])/2.0;
    }
    return -1.0;
}
int main(){
    vector<int> a = {1,2};
    vector<int> b = {3,4};
    cout<<findMedianSortedArrays(a,b)<<endl;
    return 0;
}