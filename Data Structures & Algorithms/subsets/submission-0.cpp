class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& perm){
        if(i==nums.size()){
            ans.push_back(perm);
            return;
        }
        perm.push_back(nums[i]);
        solve(i+1,nums,ans,perm);
        perm.pop_back();
        solve(i+1,nums,ans,perm);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        solve(0,nums, ans, perm);
        return ans;
    }
};
