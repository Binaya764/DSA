#include<iostream>
#include<vector>
using namespace std;

void pathFinder(vector<vector<int>> &matrix, int row, int col,string path, vector<string> &ans){
    int n = matrix.size();
    if( row>=n|| col>=n||  row<0 || col<0 || matrix[row][col]==0||matrix[row][col]==-1){
        return;
    }
    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }
    matrix[row][col]=-1;

    //Down traverse
    pathFinder(matrix,row+1,col,path+"D",ans);
    //Up traverse
    pathFinder(matrix,row-1,col,path+"U",ans);
    //left
    pathFinder(matrix,row,col-1,path+"L",ans);
    //right
    pathFinder(matrix,row, col+1,path+"R",ans);

    matrix[row][col]=1;

}

int main(){
    vector<vector<int>> matrix= {{1,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,1,1}};
    int row = 0,col =0;
    string path = "";
    vector<string> ans;
    pathFinder(matrix,row,col,path,ans);
    for(const string &p :ans){
        cout<<p<<endl;
    }
    return 0;

}