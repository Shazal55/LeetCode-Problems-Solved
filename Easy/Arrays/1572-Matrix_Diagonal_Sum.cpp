#include<iostream>
#include <vector>
using namespace std;
int diagonalSum(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int sum = 0;
    for(int i = 0; i<m; i++){
        sum += mat[i][i];
    }
    for(int i = 0; i<m; i++){
        sum += mat[i][n-i-1];
    }
    if(m%2 == 1){
        sum -= mat[m/2][n/2];
    }
    return sum;
}
int main(){
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<diagonalSum(vec)<<endl;
    return 0;
}