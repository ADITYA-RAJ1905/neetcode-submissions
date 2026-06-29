class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>>& ans, vector<int>& comb,int sum,int target){
        int n=nums.size();
        if(i>=n) return ;
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(comb);
            return;
        }
            comb.push_back(nums[i]);
            solve(i,nums,ans,comb,sum+nums[i],target);
            comb.pop_back();
            solve(i+1,nums,ans,comb,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(0,nums,ans,comb,0,target);
        return ans;
    }
};
