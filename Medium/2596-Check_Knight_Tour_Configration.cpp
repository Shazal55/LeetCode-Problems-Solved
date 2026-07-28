#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>>& grid,int row, int col, int n, int expectedVal){
    if(row <0 || col < 0 || row >= n || col >= n || grid[row][col]!= expectedVal){
        return false;
    }
    if (expectedVal == n*n-1){
        return true;
    }
    bool ans1 = isValid(grid,row-2,col+1,n,expectedVal+1);
    bool ans2 = isValid(grid,row-1,col+2,n,expectedVal+1);
    bool ans3 = isValid(grid,row+1,col+2,n,expectedVal+1);
    bool ans4 = isValid(grid,row+2,col+1,n,expectedVal+1);
    bool ans5 = isValid(grid,row+2,col-1,n,expectedVal+1);
    bool ans6 = isValid(grid,row+1,col-2,n,expectedVal+1);
    bool ans7 = isValid(grid,row-1,col-2,n,expectedVal+1);
    bool ans8 = isValid(grid,row-2,col-1,n,expectedVal+1);
    return ans1 +ans2 +ans3 +ans4 +ans5 +ans6 +ans7 +ans8 ;
}
bool checkValidGrid(vector<vector<int>>& grid) {//O(8^n^2)
    return isValid(grid,0,0,grid.size(),0);
}

int main(){
    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    cout<<checkValidGrid(grid);
    return 0;
}