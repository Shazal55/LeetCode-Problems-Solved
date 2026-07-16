#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//Brute Force
vector<vector<int>> threeSum(vector<int>& nums) {// TC : O(n^3 * log(unique_triplets)) , SC: O(unique_triplets)
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if((nums[i] + nums[j] + nums[k]) == 0){
                    vector<int> trip = {nums[i],nums[j],nums[k]};
                    sort(trip.begin(),trip.end());
                    if(s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}
//Better approach
vector<vector<int>> threeSum1(vector<int>& nums) {//TC: O(n^2 * log(unique_triplets)), SC: O(unique_triplets + n)
    int n = nums.size();
    set<vector<int>> unique_triplets;
    for(int i = 0; i<n; i++){
        int tar = -nums[i];
        set<int> s;
        for(int j = i+1; j<n; j++){
            int third = tar - nums[j];
            if(s.find(third) != s.end()){
                vector<int> trip = {nums[i] , nums[j] , third};
                sort(trip.begin(),trip.end());
                unique_triplets.insert(trip);
            } 
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(unique_triplets.begin(),unique_triplets.end());
    return ans;
}
//Optimized Approach
vector<vector<int>> threeSum2(vector<int>& nums) {//TC: O(nlogn + n^2), SC : O(unique_triplets)
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i = 0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1])
                continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]){
                    j++;
                }
            }
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(vec);
    int n = ans.size();
    int m = ans[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//Output : -1 0 1 
//        -1 -1 2 