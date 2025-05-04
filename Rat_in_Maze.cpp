class Solution {
  public:
  int n,m;
  vector<string>result;
  void solve(int i, int j,vector<vector<int>>&maze,string &path){
    //   base case 1
    if(i<0 || j<0 || i>=n || j>=m || maze[i][j]!=1){
        return ;
    }
    // base case 2
    if(i==n-1 && j==m-1){
        result.push_back(path);
        return ;
    }
    // after all base case, if you going from any path, mark it as zero
    maze[i][j]=0;
    // for the left call,mark with 'L'
    path.push_back('L');
    solve(i,j-1,maze,path);
    path.pop_back();
     // for the right call,mark with 'R'
    path.push_back('R');
    solve(i,j+1,maze,path);
    path.pop_back();
     // for the down call,mark with 'D'
    path.push_back('D');
    solve(i+1,j,maze,path);
    path.pop_back();
     // for the up call,mark with 'U'
    path.push_back('U');
    solve(i-1,j,maze,path);
    path.pop_back();
    // BEAUTY OF BACKTRACKING
    maze[i][j]=1;
    
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n=maze.size();
        m=maze[0].size();
        string path="";
        solve(0,0,maze,path);
        sort(result.begin(),result.end());
        return result;
        
    }
};
