#include <iostream>
#include <vector>
using namespace std;
int countPath(int m,int n,int row,int col,vector<vector<int>> &dp){
    if(row == m-1 && col == n-1){
        return 1;
    }
    if(row >= m || col >= n){
        return 0;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    int down = countPath(m,n,row+1,col,dp);
    int right = countPath(m,n,row,col+1,dp);
    dp[row][col] =  down + right;
    return dp[row][col];
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int> (n,-1));
    return countPath(m,n,0,0,dp);
}
int main(){
    int m = 3;
    int n = 7;
    cout<<uniquePaths(m,n)<<endl;
    return 0;
}