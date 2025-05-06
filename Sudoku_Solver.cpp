class Solution {
public:
bool isvalidplace(int row,int col,vector<vector<char>>& board,char num){
    // row check
    for(int i=0;i<board[0].size();i++){
        if(board[row][i]==num){
            return false;
        }
    }
    // colum check
    for(int i=0;i<board[0].size();i++){
        if(board[i][col]==num){
            return false;
        }
    }
    // check grid
    int sr=(row/3)*3;
    int sc=(col/3)*3;
    for(int i=sr;i<=sr+2;i++){
        for(int j=sc;j<=sc+2;j++){
            if(board[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    int n=board[0].size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            // check if cell empty or not
            if(board[row][col]=='.'){
                // check for 1 to 9
                for(char num='1';num<='9';num++){
                    if(isvalidplace(row,col,board,num)){
                        board[row][col]=num;   
                        bool nextsolve=solve(board);
                        if(nextsolve){
                            return true;
                        }else{
                            // backtrack
                            board[row][col]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
