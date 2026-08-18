class Solution {
public:
    bool solve(int i,string s,vector<int>& dp,unordered_map<string,int>& mp){
        int n=s.size();
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n;j++){
            string word=s.substr(i,j-i+1);
            if(mp.find(word)!=mp.end()){
                if(solve(j+1,s,dp,mp)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n,-1);
        unordered_map<string,int> mp;
        for(string word:wordDict){
            mp[word]++;
        }
        return solve(0,s,dp,mp);

    }
};