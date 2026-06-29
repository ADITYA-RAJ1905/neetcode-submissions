class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs){
            string count(26,'0');
            for(char c:s){
                count[c-'a']+=1;
            }
            mp[count].push_back(s);
            
        }
        vector<vector<string>> ans;
            for(auto ele:mp){
                ans.push_back(ele.second);
            }
        return ans;
    }
};
