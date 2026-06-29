class Solution {
public:
    void solve(vector<int>& nums, vector<int>& perm,
               vector<vector<int>>& ans, vector<bool>& visited) {

        // Base case
        if (perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (visited[i])
                continue;

            visited[i] = true;
            perm.push_back(nums[i]);

            solve(nums, perm, ans, visited);

            perm.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> perm;
        vector<bool> visited(nums.size(), false);

        solve(nums, perm, ans, visited);

        return ans;
    }
};