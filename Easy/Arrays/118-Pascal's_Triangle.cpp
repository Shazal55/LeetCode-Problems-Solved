#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {//O(n^2)
    vector<vector<int>> ans;
    for(int i =0; i<numRows; i++){
        vector<int> row;
        for(int j = 0; j<=i; j++){
            if(j==0 || j==i){
                row.push_back(1);
            }
            else{
                row.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
        }
        ans.push_back(row);
    }
    return ans;
}
int main(){
    vector<vector<int>> ans = generate(5);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Output : 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
*/