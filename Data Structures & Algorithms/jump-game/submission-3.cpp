class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        if(n==1) return true;
        if(nums[0]==0) return false;
        int maxi=0;
        int jump=0;
        while(i<n){
            if(maxi>=n-1){
                return true;
            }
            if(nums[i]==0 and maxi==i) return false;
            jump=nums[i];
            maxi=max(maxi,i+jump);
            i++;
        }
        return false;
    }
};
