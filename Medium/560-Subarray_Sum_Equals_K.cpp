#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//Brute Force
int subarraySum(vector<int>& nums, int k) {//TC: O(n^2)
    int n = nums.size(); 
    int count = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum+=nums[j];
            if(sum == k) count++;
        }
    }
    return count;
}
//Optimized Approach
int subarraySum1(vector<int>& nums, int k) { //TC: O(n) , SC: O(n)
    int n = nums.size(); 
    int count = 0;
    vector<int> prefixSum(n,0);
    unordered_map<int,int> m;
    prefixSum[0] = nums[0];
    for(int i = 1; i<n; i++){
        prefixSum[i] = prefixSum[i-1]+ nums[i];
    }    
    for(int j=0; j<n; j++){
        if(prefixSum[j] == k){
            count++;
        }
        int val = prefixSum[j] - k;
        if(m.find(val)!= m.end()){
            count += m[val];
        }
        if(m.find(prefixSum[j]) == m.end()){
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]]++;
    }
    return count;
}
int main(){
    vector<int> n = {1,2,3};
    int k = 3;
    cout<<subarraySum(n,k)<<endl;
}