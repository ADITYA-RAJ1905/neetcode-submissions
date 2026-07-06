class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& visited){
        visited[node]=1;
        for(auto neighbor:adj[node]){
            if(neighbor==parent){
                continue;
            }
            if(visited[neighbor]){
                return false;
            }
            if(!dfs(neighbor,node,adj,visited)){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(!dfs(0,-1,adj,visited)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
