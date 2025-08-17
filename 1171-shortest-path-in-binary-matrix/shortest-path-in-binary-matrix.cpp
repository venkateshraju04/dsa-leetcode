class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1 && grid[0].size() == 1)
            return 1;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dist=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0  && j==0)continue;
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow==n-1 && ncol==n-1)return dist+1;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist+1<dis[nrow][ncol] && grid[nrow][ncol]==0){
                        dis[nrow][ncol]=dist+1;
                        
                        q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};