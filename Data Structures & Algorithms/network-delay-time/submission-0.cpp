class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> d(n+1,INT_MAX);
        d[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> ele=pq.top();
            pq.pop();
            int dist=ele.first;
            int u=ele.second;
            if(dist>d[u]){
                continue;
            }

            for(auto neighbor:adj[u]){
                int v=neighbor.first;
                int w=neighbor.second;
                if(d[u]+w<d[v]){
                    d[v]=d[u]+w;
                    pq.push({d[v],v});
                }
            }
        }

        for(int i=1;i<=n;i++){

            if(d[i]==INT_MAX)
                return -1;

            ans=max(ans,d[i]);
        }
        return ans;
    }
};
