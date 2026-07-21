#include <iostream>
#include <vector>
using namespace std;
void getAnswer(vector<vector<int>> &Maze,int row,int col,string path, vector<string> &ans){
    if(row<0 || col <0  || row >=Maze.size() || col >= Maze[0].size() || Maze[row][col] == 0 || Maze[row][col] == -1){
        return;
    }
    
    if(row == Maze.size()-1 && col == Maze[0].size()-1){
        ans.push_back(path);
        return;
    }
    Maze[row][col] = -1;
    getAnswer(Maze,row+1,col,path+"D",ans);//Down
    getAnswer(Maze,row-1,col,path+"U",ans);//Up
    getAnswer(Maze,row,col+1,path+"R",ans);//Right
    getAnswer(Maze,row,col-1,path+"L",ans);//Left
    Maze[row][col] = 1;
}
vector<string> findPath(vector<vector<int>> &Maze){
    int n = Maze.size();
    int m = Maze[0].size();
    vector<string> ans;
    string path = "";
    getAnswer(Maze,0,0,path,ans);
    return ans;
}
int main(){
    vector<vector<int>> Maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans = findPath(Maze);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
/*
The problem tells us to find the number of possible paths to move from (0,0) to (n,n) in n possible steps
Output:
DDRDRR
DRDDRR
*/
