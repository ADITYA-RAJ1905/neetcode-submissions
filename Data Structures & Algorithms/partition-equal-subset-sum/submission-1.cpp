class Solution {
public:
    bool solve(int i,int sum,vector<vector<int>>& dp,vector<int> nums,int target){
        int n=nums.size();
        if(i<0 || i>=n || sum>target){
            return false;
        }
        if(sum==target){
            return true;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        dp[i][sum]= solve(i+1,sum,dp,nums,target) ||solve(i+1,sum+nums[i],dp,nums,target);
        return dp[i][sum];
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int s:nums){
            sum+=s;
        }
        if(sum%2!=0) return false;
        int t=sum/2;
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        return solve(0,0,dp,nums,t);
    }
};
