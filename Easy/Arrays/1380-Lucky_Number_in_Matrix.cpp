#include <iostream>
#include <vector>
using namespace std;
vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rowMin(m);
    vector<int> colMax(n);
    vector<int> ans;
    for(int i =0 ; i<m; i++){
        rowMin[i] = matrix[i][0];
        for(int j = 1; j<n; j++){
            rowMin[i] = min(rowMin[i],matrix[i][j]);
        }
    }
    for(int j = 0; j<n; j++){
        colMax[j] = matrix[0][j];
        for(int i=1; i<m; i++){
            colMax[j] = max(colMax[j],matrix[i][j]);
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]){
                ans.push_back(matrix[i][j]);
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> vec = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> ans = luckyNumbers(vec);
    for(int val : ans){
        cout<<val<<endl;
    }
    return 0;
}