class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(string s:strs){
            ans+=s;
            ans+="~";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp="";
        for(char c:s){
            if(c=='~'){
                ans.push_back(temp);
                temp="";
                continue;
            }
            temp+=c;
        }
        return ans;
    }
};
