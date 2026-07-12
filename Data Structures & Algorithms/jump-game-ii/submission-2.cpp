class Solution {
public:
    int solve(int i,vector<int>& dp,vector<int>& nums){
        int n=nums.size();
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(nums[i]==0){
            return INT_MAX;
        }
        int ans=INT_MAX;
        for(int j=1+i;j<=min(n-1,i+nums[i]);j++){
            int jumps=solve(j,dp,nums);
            if(jumps!=INT_MAX) ans=min(ans,1+jumps);
        }
        return dp[i]=ans;
        
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,dp,nums);
    }
};
