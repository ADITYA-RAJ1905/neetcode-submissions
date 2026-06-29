class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);
        for(char c:s){
            arr[c-'a']++;
        }
        for(char c:t){
            if(arr[c-'a']==0){
                return false;
            }
            else{
                arr[c-'a']--;
            }
        }
        for(int i:arr){
            if(i>0) return false;
        }
        return true;
    }
};
