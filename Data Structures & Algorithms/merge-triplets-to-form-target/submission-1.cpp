class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first=INT_MIN;
        int second=INT_MIN;
        int third=INT_MIN;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1]|| triplets[i][2]>target[2]){
                continue;
            }
            first=max(first,triplets[i][0]);
            second=max(second,triplets[i][1]);
            third=max(third,triplets[i][2]);
        }
        if(first!=target[0] || second!=target[1]|| third!=target[2]){
            return false;
        }
        return true;
    }
};
