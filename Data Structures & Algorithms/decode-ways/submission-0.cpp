class Solution {
public:
    int solve(int i,vector<int>& dp,string s){
        int n=s.size();
        if(i==n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int lol=solve(i+1,dp,s);
        if(i+1<n && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            lol+=solve(i+2,dp,s);
        }
        return dp[i]=lol;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,dp,s);
    }
};
