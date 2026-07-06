class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        while(true){
            int sum=0;
            while(n>0){
                int digit=n%10;
                n=n/10;
                sum+=digit*digit;
            }
            if(sum==1){
                return true;
            }
            if(mp.find(sum)!=mp.end()){
                return false;
            }
            n=sum;
            mp[sum]=1;
        }
        return false;
    }
};
