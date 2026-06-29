class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int n=heights.size();
        int right=n-1;
        int ans=INT_MIN;
        while(left<=right){
            int area=(right-left)*min(heights[left],heights[right]);
            ans=max(ans,area);
            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};
