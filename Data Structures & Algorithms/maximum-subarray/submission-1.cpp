class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        bool flag=true;
        int maxi=INT_MIN;
        for(int i:nums){
            if(i>0) flag=false;
            maxi=max(maxi,i);
        }
        if(flag){
            return maxi;
        }
        int i=0;
        int ans=0;
        int sum=0;
        while(i<n){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            ans=max(ans,sum);
            i++;
        }
        return ans;
    }
};
