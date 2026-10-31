#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col,char digit){
    //For horizontal check
    for(int j = 0; j<9; j++){
        if(board[row][j] == digit){
            return false;
        }
    }

    //For vertical Check
    for(int i = 0; i<9; i++){
        if(board[i][col]== digit){
            return false;
        }
    }
    //Check for 3x3 grid
    int startRow= (row/3)*3;
    int startCol= (col/3)*3;
    for(int i = startRow; i<= startRow+2; i++){
        for(int j = startCol; j<= startCol+2; j++){
            if(board[i][j]== digit){
                return false;
            }
        }
    }
    return true;

}

bool sudokuSolver(vector<vector<char>> &board, int row, int col, vector<vector<char>> &solvedSudoku){
    if(row == 9){
        solvedSudoku= board;
        return true;
    }

    int nextRow = row, nextCol = col+1;

    //if the digit reaches the end of the row
    if(nextCol == 9){
        nextRow = row+1;
        nextCol = 0;
    }

    if(board[row][col] != '.'){
        return sudokuSolver(board, nextRow, nextCol, solvedSudoku);
    }

    for(char digit = '1'; digit<='9'; digit++){
        if(isValid(board,row,col,digit)){
            board[row][col]=digit;
        
        if(sudokuSolver(board,nextRow,nextCol,solvedSudoku)){
            return true;
        }
        board[row][col]='.';}
    }
    return false;


}


int main() {
    // Sample unsolved Sudoku board
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    vector<vector<char>> solvedSudoku;

    if (sudokuSolver(board, 0, 0, solvedSudoku)) {
        cout << "Sudoku Solved Successfully!\n\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << solvedSudoku[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}