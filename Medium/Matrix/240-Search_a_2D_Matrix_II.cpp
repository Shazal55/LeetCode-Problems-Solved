#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {//TC: O(n+m)
    int n = matrix.size();
    int rows = 0;
    int cols = matrix[0].size() - 1;
    while(cols>= 0 && rows <= n-1){
        if(target == matrix[rows][cols]){
            return true;
        }
        else if(target < matrix[rows][cols]){
            cols--;
        }
        else{
            rows++;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> vec = {{1,2,4},{3,5,7},{6,8,9},{10,11,12}};
    int target = 5;
    cout<<searchMatrix(vec,target)<<endl;
    return 0;
}