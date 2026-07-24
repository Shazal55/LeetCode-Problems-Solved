#include <iostream>
#include <vector>
using namespace std;
vector<int> getRow(int rowIndex) {
    vector<vector<int>> ans;
    for(int i = 0; i<=rowIndex; i++){
        vector<int> row;
        for(int j= 0; j<=i; j++){
            if(j == 0 || j == i){
                row.push_back(1);
            }
            else{
                row.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
        }
        ans.push_back(row);
    }
    return ans[rowIndex];
}
int main(){
    vector<int> ans = getRow(3);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
Output :  1 3 3 1 
*/