#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {//By creating seperate vector
    int k = 0;
    int size = m+n;
    vector<int> final(size,0);
    for(int i = 0; i<m;i++){
        final[k] = nums1[i];
        k++;
    }
    for(int j = 0; j < n; j++){
        final[k] = nums2[j];
        k++;
    }
    sort(final.begin(),final.end());
    nums1 = final;
    for(int val : final){
        cout<<val<<" ";
    }
    cout<<endl;
}
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = 0;
    int size = m+n;
    for(int i = m; i<size;i++){
        nums1[i] = nums2[k];
        k++;
    }
    sort(nums1.begin(),nums1.end());
    for(int val : nums1){
        cout<<val<<",";
    }
    cout<<endl;
}
int main(){
    vector<int> vec1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> vec2 = {2,5,6};
    int n = 3;
    merge1(vec1,m,vec2,n);
}