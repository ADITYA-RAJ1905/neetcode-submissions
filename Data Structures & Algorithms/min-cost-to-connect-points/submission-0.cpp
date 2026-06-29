class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>> adj;
        int n=points.size();
        for(int i=0;i<n;i++){
            int u=points[i][0];
            int v=points[i][1];
            for(int j=i+1;j<n;j++){
                int u1=points[j][0];
                int v1=points[j][1];
                int dist=abs(u-u1)+abs(v-v1);
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }
        int cost=0;
        unordered_set<int> visited;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        minh.push({0,0});
        while(visited.size()<n){
            auto curr=minh.top();
            minh.pop();
            int c=curr.first;
            int i=curr.second;
            if(visited.count(i)){
                continue;
            }
            cost+=c;
            visited.insert(i);
            for(const auto& neighbor:adj[i]){
                int nc=neighbor.first;
                int ni=neighbor.second;
                if(!visited.count(ni)){
                    minh.push({nc,ni});
                }
            }
        }
        return cost;
    }
};
