#include <iostream>
#include <memory>
#include <vector>

using namespace std;


bool is_safe(vector<vector<int>> &board, int r, int c, int n){


    //check the column
    for( int i = 0;i<9;i++){
        if(board[i][c] == n){
            return false;
        }
    }

    //check for column
    for (int i=0; i<9; i++){
        if(board[r][i] == n){
            return false;
        }
    }

    //check in the box
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;

    for(int i = row_start; i<row_start+3; i++){
        for(int j = col_start; j<col_start+3; j++){
            if(board[i][j] == n){
                return false;
            }
        }
    }

    return true;

    
}

bool solve_sudoku(vector<vector<int>> & board, int r, int c){ // r is row, c is column
    
    //base case 
    if(r == 9) { // the end of the row, we have solved the puzzle
        return true;
    }
    
    // //other cases
    if(c == 9){ // the end of the column, move to the next row
        return solve_sudoku(board, r+1, 0);
    }

    //skip the pre-filled cells
    if(board[r][c] != 0){ // if the cell is not empty, skip it
        return solve_sudoku(board, r, c+1);
    }

    //recursive cases
    for(int i = 1; i<=9; i++){ // try each number from 1 to 9
        if(is_safe(board, r, c, i)){ // if the number is safe to put in the cell
            board[r][c] = i; // put the number in the cell
            bool success = solve_sudoku(board, r, c+1); // try to solve the rest of the puzzle
            if(success){ // if the rest of the puzzle can be solved
                return true; // return true for the whole puzzle
            }
            board[r][c] = 0; // if the rest of the puzzle cannot be solved
            // reset the cell to empty, and try the next number
        }
    }

    return false; // if no number can be put in the cell, return false



}

//write a function to convert 2d char vector to 2d int vector

// vector<vector<int>> char_vec_int_vec(vector<vector<char>> &board){
//     vector<vector<int>> new_board;
//     for(int i = 0; i<9; i++){
//         vector<int> row;
//         for(int j = 0; j<9; j++){
//             row.push_back(board[i][j] - '0');
//         }
//         new_board.push_back(row);
//     }
//     return new_board;
// }

//write a function to convert 2d int vector to 2d char vector

// vector<vector<char>> int_vec_char_vec(vector<vector<int>> &board){
//     vector<vector<char>> new_board;
//     for(int i = 0; i<9; i++){
//         vector<char> row;
//         for(int j = 0; j<9; j++){
//             row.push_back(board[i][j] + '0');
//         }
//         new_board.push_back(row);
//     }
//     return new_board;
// }
//



int main () {

    vector<vector<int>> board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    solve_sudoku(board, 0, 0);

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


// cout<< "Enter the row:  ";
// int r;
// cin>>r;
// cout<< "Enter the column:  ";
// int c;
// cin>>c;
// cout<< "Enter the number:  ";
// int n;
// cin>>n;
// cout<< is_safe(board, r-1, c-1, n)<<endl;

/*


   class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
            if(board[row][i] == ch){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};



*/


/*
*/
