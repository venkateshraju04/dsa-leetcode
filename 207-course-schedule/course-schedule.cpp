class Solution {
public:
    bool dfs(int node,vector<int> &visited, vector<int> &pathVisited,vector<int> adj[]){
        visited[node]=1;
        pathVisited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
            if(dfs(it,visited,pathVisited,adj)) return true;
            }else if(pathVisited[it]){
                return true;
            }
        }
        pathVisited[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,pathVisited,adj))return false;
            }
        }
        return true;
    }
};