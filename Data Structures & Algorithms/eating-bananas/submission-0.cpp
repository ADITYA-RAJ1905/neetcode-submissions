class Solution {
public:
    bool canplace(int k,int h,vector<int>& piles){
        int i=0;
        int n=piles.size();
        int c=0;
        for(int i=0;i<n;i++){
            c+=(piles[i]+k-1)/k;
            
        }
        return c<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int p:piles){
            maxi=max(maxi,p);
        }
        int left=1,right=maxi;
        int ans=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canplace(mid,h,piles)){
                ans=min(ans,mid);
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
