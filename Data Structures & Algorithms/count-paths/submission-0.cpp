class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dp,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=solve(i+1,j,dp,n,m) + solve(i,j+1,dp,n,m) ;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,dp,n,m);
    }
};
