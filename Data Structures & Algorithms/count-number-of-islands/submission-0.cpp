class Solution {
public:
    void solve(int i,int j,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n ||j>=m || grid[i][j]=='0' ||grid[i][j]=='#'){
            return;
        }
        if(grid[i][j]=='1'){
            grid[i][j]='#';
        }
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    solve(i,j,grid);
                    c++;
                }
            }
        }
        return c;
    }
};
