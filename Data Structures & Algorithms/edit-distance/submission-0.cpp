class Solution {
public:
    int solve(int i,int j,string t,string p,vector<vector<int>>& dp){
        int n=t.size();
        int m=p.size();
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(t[i]==p[j]){
            dp[i][j]=solve(i+1,j+1,t,p,dp);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            dp[i][j]=min(1+solve(i,j+1,t,p,dp),min(1+solve(i+1,j+1,t,p,dp),1+solve(i+1,j,t,p,dp)));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,dp);
    }
};
