#include <iostream>
#include <vector>
using namespace std;

long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) { //TC : O(n + M)
    long long sum = 0;
    long long k = (long long)k1 + k2;
    vector<int> diff(nums1.size());
    int maxi = 0;
        

    for(int i = 0; i<nums1.size(); i++){
        diff[i] = (abs(nums1[i] - nums2[i]));
        maxi = max(maxi,diff[i]);
    }

    vector<long long> freq(maxi+1,0);

    for(int d : diff){
        freq[d]++;
    }

    for(int d = maxi; d > 0 && k > 0; d--){
        long long count = freq[d];
        long long moves = min(k,count);
        freq[d] -= moves;
        freq[d-1] += moves;
        k -= moves;
    }

    for(int d = 1; d<= maxi; d++){
        sum += freq[d] * d* d;
    }

    return sum;
}
int main(){
    vector<int> nums1 = {1,4,10,12};
    vector<int> nums2 = {5,8,6,9};
    int k1 = 1;
    int k2 = 1;
    long long ans =  minSumSquareDiff(nums1,nums2,k1,k2);
    cout<<"Minimum Square difference : "<<ans<<endl;
    return 0;
}
//Minimum Square difference : 43
