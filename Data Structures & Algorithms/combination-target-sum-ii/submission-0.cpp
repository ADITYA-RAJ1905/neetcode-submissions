class Solution {
public:
    void solve(int i,vector<int>& comb,int sum,vector<vector<int>>& ans,vector<int>& nums,int target){
        int n=nums.size();
        if(sum==target){
            ans.push_back(comb);
            return;
        }
        if(i==n || sum>target){
            return;
        }
        
        comb.push_back(nums[i]);
        solve(i+1,comb,sum+nums[i],ans,nums,target);
        comb.pop_back();
        int j=i+1;
        while(j<n && nums[j]==nums[i]){
            j++;
        }
        solve(j,comb,sum,ans,nums,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        solve(0,comb,0,ans,candidates,target);
        return ans;
    }
};
