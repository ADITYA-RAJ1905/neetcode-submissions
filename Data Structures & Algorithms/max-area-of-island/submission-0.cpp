class Solution {
public:
    void solve(int i,int j,vector<vector<int>>& grid,int& c, int n,int m){
        if(i<0 || j<0 ||i>=n ||j>=m||grid[i][j]==-1 || grid[i][j]==0){
            return;
        }
        if(grid[i][j]==1){
            c++;
            grid[i][j]=-1;
        }
        solve(i+1,j,grid,c,n,m);
        solve(i,j+1,grid,c,n,m);
        solve(i,j-1,grid,c,n,m);
        solve(i-1,j,grid,c,n,m);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=0;
                if(grid[i][j]==1){
                    solve(i,j,grid,c,n,m);
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};
