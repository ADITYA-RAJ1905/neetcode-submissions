class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int ans=-1;
        vector<int> dirx={1,-1,0,0};
        vector<int> diry={0,0,1,-1};
        while(!q.empty()){
            ans++;
            int s=q.size();
            while(s--){
                auto [i,j]=q.front();
                q.pop();
            
            for(int k=0;k<4;k++){
                int nx=i+dirx[k];
                int ny=j+diry[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1) continue;
                if(grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
