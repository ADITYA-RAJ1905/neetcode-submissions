class Solution {
public:
    void solve(int i,vector<vector<int>>& ans,vector<int>& nums,vector<int> curr){
        int n=nums.size();
        ans.push_back(curr);
        for(int j=i;j<n;j++){
            if(j>i &&  nums[j]==nums[j-1]){
                continue;
            }
            curr.push_back(nums[j]);
            solve(j+1,ans,nums,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(0,ans,nums,{});
        return ans;
    }
};
