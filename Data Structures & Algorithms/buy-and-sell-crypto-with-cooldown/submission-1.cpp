class Solution {
public:
    int solve(int i,int j,vector<int>& prices, vector<vector<int>>& dp){
        int n=prices.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==0){
            dp[i][j]=max(prices[i]+solve(i+2,1,prices,dp),solve(i+1,0,prices,dp));
        }
        else if(j==1){
            dp[i][j]=max(-prices[i]+solve(i+1,0,prices,dp),solve(i+1,1,prices,dp));
        }
        return dp[i][j];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
