class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int s) {
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        int n=hand.size();
        if(n%s!=0) return false;
        for(int i:hand){
            mp[i]++;
        }
        for(int i:hand){
            if(mp[i]==0){
                continue;
            }
            for(int j=0;j<s;j++){
                if(mp[i+j]==0) return false;
                mp[i+j]--;
            }
        }
        return true;
    }
};
