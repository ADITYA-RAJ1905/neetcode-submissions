class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int j=0;j<=n;j++){
            int one=0;
            int i=j;
            while(i){
                if(i&1) one++;
                i=i>>1;
            }
            ans.push_back(one);
        }
        return ans;
    }
};
