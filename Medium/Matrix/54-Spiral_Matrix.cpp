#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {//O(m*n)
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    int srow = 0;
    int erow = m-1;
    int scol = 0;
    int ecol = n-1;
    int size  = n*m;
    while(srow<=erow && scol<= ecol){
        for(int j = scol; j<=ecol; j++){
            ans.push_back(matrix[srow][j]);
        }
        for(int i = srow+1; i<=erow; i++){
            ans.push_back(matrix[i][ecol]);
        }
        for(int j = ecol-1; j>=scol; j--){
            if(srow == erow)
                break;
            ans.push_back(matrix[erow][j]);
        }
        for(int i = erow-1; i>=srow+1; i--){
            if(scol == ecol){
                break;
            }
            ans.push_back(matrix[i][scol]);
        }
        srow++;
        erow--;
        scol++;
        ecol--;
    }
    return ans;
}
int main(){
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(vec);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
}