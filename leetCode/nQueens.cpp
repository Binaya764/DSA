#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int noOfQueens){
    //for horizontal check
    for(int j = 0; j<noOfQueens; j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    for(int i = 0 ; i<noOfQueens; i ++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for( int i =row, j =col; i>=0&&j>=0; i--, j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i =row, j=col; i>=0&& j<noOfQueens; i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<string> &board, int row, int noOfQueens, vector<vector<string>> &ans){
    if(row == noOfQueens){
        ans.push_back(board);
        return;
    }
    for(int j=0; j<noOfQueens; j++){
        if(isSafe(board,row,j,noOfQueens)){
            board[row][j]= 'Q';
            solveNQueens(board,row+1,noOfQueens,ans);
            board[row][j]= '.';

        }
    }
   

}

int main(){
    int n=4;
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;
    int row = 0;
    solveNQueens(board,row,n,ans);
    cout << "Total solutions found: " << ans.size() << "\n\n";

    
    for(int s = 0; s < ans.size(); s++){
        cout << "Solution " << s + 1 << ":\n";
        for(int i = 0; i < ans[s].size(); i++){
            cout << "{ ";
            for(int j = 0; j < ans[s][i].size(); j++){
                cout << ans[s][i][j] << " ";
            }
            cout << "}\n";
        }
        cout << endl;
    }

    return 0;
}