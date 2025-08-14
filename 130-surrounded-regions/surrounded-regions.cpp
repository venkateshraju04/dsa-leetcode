class Solution {
public:
    
    void dfs(int row,int col, vector<vector<int>> &visited,vector<vector<char>> &board, int delrow[], int delcol[]){
        visited[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,visited,board,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,visited,board,delrow,delcol);
            }
            if(!visited[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,visited,board,delrow,delcol);
            }
        }
        for(int j=0;j<m;j++){
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(0,j,visited,board,delrow,delcol);
            }
            if(!visited[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,visited,board,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};