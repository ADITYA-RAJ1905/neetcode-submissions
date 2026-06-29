class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto ele:mp){
            bucket[ele.second].push_back(ele.first);
        }
        vector<int> ans;
        for(int i=n;i>=1&&k>0;i--){
            for(int j:bucket[i]){
                ans.push_back(j);
                k--;
            
                if(k==0) break;
            }
        }
        return ans;
    }
};
