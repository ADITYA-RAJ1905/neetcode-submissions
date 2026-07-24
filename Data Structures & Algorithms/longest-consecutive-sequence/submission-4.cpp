class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> mp;
        for(int n:nums){
            mp.insert(n);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()){
                int c=1;
                int num=nums[i]+1;
                while(mp.find(num)!=mp.end()){
                    c++;
                    num++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};
