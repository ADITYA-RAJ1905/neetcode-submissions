class Solution {
public:
    int solve(int i,int end,vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        if(i<0 || i>end){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=max(nums[i]+solve(i+2,end,nums,dp),solve(i+1,end,nums,dp));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,-1);
        vector<int> dp1(n,-1);
        return max(solve(0,n-2,nums,dp),solve(1,n-1,nums,dp1));
    }
};
