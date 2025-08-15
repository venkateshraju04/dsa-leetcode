class Solution {
public:
    void dfs(int row, int col, int delrow[], int delcol[],vector<vector<int>>& visited,vector<vector<int>>& grid){
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,delrow,delcol,visited,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(i,0,delrow,delcol,visited,grid);
            }
            if(!visited[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,delrow,delcol,visited,grid);
            }
        }
        for(int j=0;j<m;j++){
            if(!visited[0][j] && grid[0][j]==1){
                dfs(0,j,delrow,delcol,visited,grid);
            }
            if(!visited[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,delrow,delcol,visited,grid);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1 && !visited[i][j])count++;
            }
        }
        return count;
    }
};