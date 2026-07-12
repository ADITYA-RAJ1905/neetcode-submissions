class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<int> open;
        stack<int> stars;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                stars.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }
                else if(open.empty() && !stars.empty()){
                    stars.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!open.empty()){
            if(stars.empty()){
                return false;
            }
            else{
                while(!open.empty() && !stars.empty()){
                    int t=stars.top();
                    stars.pop();
                    if(t<open.top()){
                        return false;
                    }
                    open.pop();
                }
            }
        }
        return open.empty();
    }
};
