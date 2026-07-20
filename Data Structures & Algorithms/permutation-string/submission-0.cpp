class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        for(int i=0;i<s1.size();i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }
        int match=0;

        for(int i=0;i<26;i++){
            if(c1[i]==c2[i]){
                match++;
            }
        }
        int left=0;
        for(int right=s1.size();right<s2.size();right++){
            if(match==26){
                return true;
            }
            int idx=s2[right]-'a';
            c2[idx]++;
            if(c1[idx]==c2[idx]){
                match++;
            }
            else if(c1[idx]+1==c2[idx]){
                match--;
            }
            idx=s2[left]-'a';
            c2[idx]--;
            if(c1[idx]==c2[idx]){
                match++;
            }
            else if(c1[idx]-1==c2[idx]){
                match--;
            }
            left++;
        }
        return match==26;
    }
};
