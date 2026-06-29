class Solution {
public:
    void solve(queue<pair<int,int>>& q,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int dist=0;
        vector<int> dirx={1,-1,0,0};
        vector<int> diry={0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            dist++;
            for(int i=0;i<4;i++){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }
                if(grid[nx][ny]==INT_MAX){
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        solve(q,grid);
    }
};
