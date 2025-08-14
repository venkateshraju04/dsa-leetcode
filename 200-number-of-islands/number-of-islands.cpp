class Solution {
public:
    void dfs(int row,int col,vector<vector<char>> &grid, vector<vector<int>>& visited){
        int n=grid.size();
        int m=grid[0].size();

        if(row<0 || row>=n || col<0 || col>=m || visited[row][col] || grid[row][col]=='0')
            return;
        visited[row][col]=1;
        dfs(row+1,col,grid,visited);
        dfs(row-1,col,grid,visited);
        dfs(row,col+1,grid,visited);
        dfs(row,col-1,grid,visited);
        
            
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};