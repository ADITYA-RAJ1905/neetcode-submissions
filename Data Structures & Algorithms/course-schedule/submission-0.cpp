class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& visited){
        if(visited[i]==1){
            return true;
        }
        if(visited[i]==2){
            return false;
        }
        visited[i]=1;
        for(int neigh:adj[i]){
            if(dfs(neigh,adj,visited)){
                return true;
            }
        }
        visited[i]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        for(int i=0;i<prereq.size();i++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(dfs(i,adj,visited)){
                    return false;
                }
            }
        }
        return true;
    }
};
