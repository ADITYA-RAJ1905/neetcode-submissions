class Solution {
public:
    void solve(int i,string comb,string digits,vector<string>& letters,vector<string>& ans){
        if(comb.size()==digits.size()){
            ans.push_back(comb);
            return;
        }
        int idx=digits[i]-'0';
        for(char j:letters[idx]){
            solve(i+1,comb+j,digits,letters,ans);
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};        
        vector<string> ans;
        solve(0,"",digits,letters,ans);
        return ans;
    }
};
