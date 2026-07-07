class Solution {
public:
    int solve(int i,int sum,vector<int>& coins, vector<vector<int>>& dp,int target){
        int n=coins.size();
        if(i>=n || sum>target){
            return 0;
        }
        if(sum==target){
            return 1;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        dp[i][sum]=solve(i,sum+coins[i],coins,dp,target)+solve(i+1,sum,coins,dp,target);
        return dp[i][sum];
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0,0,coins,dp,amount);
    }
};
