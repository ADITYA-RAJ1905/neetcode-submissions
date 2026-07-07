class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});
        }
        while(k>0){
            pair<int,pair<int,int>> ele=pq.top();
            pq.pop();
            ans.push_back({ele.second.first,ele.second.second});
            k--;
        }
        return ans;
    }
};
