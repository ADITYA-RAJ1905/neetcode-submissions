class Solution {
public:
    void solve(string curr,int o,int c,int n,vector<string>& ans){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(o<n){
            solve(curr+'(',o+1,c,n,ans);
        }
        if(c<o){
            solve(curr+')',o,c+1,n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("",0,0,n,ans);
        return ans;
    }
};
