// ✅ N-Queens Problem — Goal
// We are given a number n, and we need to place n queens on an n x n chessboard such that:

// No two queens attack each other.

// Return all valid board configurations.

// Queens can attack vertically, horizontally, and diagonally.

// 🧠 Approach & Thought Process
// 🔹 Step-by-Step Thought Process:
// One Queen per Row: We place one queen in each row.
// Try All Columns: For every row, try to place the queen in every column.

// Safety Check: Before placing a queen, check:
// Is there another queen above (same column)?
// Is there a queen on the left diagonal (↖)?
// Is there a queen on the right diagonal (↗)?

// Recursive Call: If it’s safe to place , place the queen and move to the next row (row + 1).
// Backtrack: After exploring that path, remove the queen (i.e., reset '.') to explore other possibilities.
// Base Case: If row == N, we have placed all queens safely. Add the board to the result.

// Note*:-we must reset the board to remove the queen we placed earlier, so we can try placing a queen in the next column of the same Row.
  
class Solution {
public:
    vector<vector<string>>result;
    int N;
    bool isSafe(vector<string>&board,int row,int col){
        // first solve for upward direction
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        // second solve for left upward diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        // third solve for right upward diagonal
        for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true; 
    }
    void solve( vector<string>&board,int row){
        // base case
        if(row==N){
            result.push_back(board);
            return ;
        }
        
        for(int col=0;col<N;col++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                solve(board,row+1);
                // backtrack for above next colum
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // make board first
        vector<string>board(n,string(n,'.'));
        N=n;
        int row=0;
        solve(board,row);
        return result;
    }
};


