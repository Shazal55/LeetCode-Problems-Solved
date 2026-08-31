#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {//brute_Force approach TC: O(n*m)
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0;i<n; i++){
        for(int j = 0; j<m; j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------
bool search_in_Row(vector<vector<int>> matrix, int target, int row){
    int n = matrix[0].size();
    int st = 0;
    int end = n-1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(target == matrix[row][mid]){
            return true;
        }
        else if(target > matrix[row][mid]){
            st = mid + 1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}
bool searchMatrix1(vector<vector<int>>& matrix, int target) { //TC : log(m*n)
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 1;
    int startRow = 0;
    int endRow = m-1;
    while(startRow <= endRow){
        int midRow = startRow + (endRow - startRow)/2;
        if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
            return search_in_Row(matrix,target,midRow);
        }
        else if(target > matrix[midRow][n-1]){
            startRow = midRow + 1;
        }
        else{
            endRow = midRow - 1;
        }
    }
    return false;
}
//-----------------------------------------------------------------------------------
int main(){
    vector<vector<int>> vec = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 34;
    if(searchMatrix1(vec,target)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}