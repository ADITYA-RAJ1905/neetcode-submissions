class Solution {
public: 
    int solve(int i,int j,vector<vector<int>>& dp,string s, string t){
        int n=s.size();
        int m=t.size();
        if(i<0 || i>=n || j<0 ||j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            dp[i][j]=1+solve(i+1,j+1,dp,s,t);
        }
        else{
            dp[i][j]=max(solve(i+1,j,dp,s,t), solve(i,j+1,dp,s,t));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,dp,text1,text2);
    }
};
