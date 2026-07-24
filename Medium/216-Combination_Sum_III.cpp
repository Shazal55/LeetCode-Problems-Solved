#include <iostream>
#include <vector>
using namespace std;
void combSum(vector<vector<int>> &ans,vector<int> &comb,int start, int limit, int sum){
    if(sum == 0 && limit == 0){
        ans.push_back(comb);
        return;
    }
    if(sum < 0 || limit == 0){
        return;
    }
    for(int i = start; i<=9; i++){
        comb.push_back(i);
        combSum(ans,comb,i+1,limit-1,sum-i);
        comb.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> comb;
    combSum(ans,comb,1,k,n);
    return ans;
}
int main(){
    int limit = 3;
    int target = 9;
    vector<vector<int>> ans = combinationSum3(limit,target);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Output : 
1 2 6 
1 3 5 
2 3 4
*/