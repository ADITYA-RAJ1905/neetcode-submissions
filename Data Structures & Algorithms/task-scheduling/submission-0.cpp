class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> mp;

        for(char c : tasks)
            mp[c]++;

        priority_queue<pair<int,char>> pq;

        for(auto &ele : mp)
            pq.push({ele.second, ele.first});

        int ans = 0;

        while(!pq.empty()) {

            int temp = n + 1;

            queue<pair<int,char>> q;

            while(temp > 0 && !pq.empty()) {

                auto task = pq.top();
                pq.pop();

                task.first--;

                if(task.first > 0)
                    q.push(task);

                ans++;
                temp--;
            }

            while(!q.empty()) {
                pq.push(q.front());
                q.pop();
            }

            // Don't count idle time after the last cycle
            if(!pq.empty())
                ans += temp;
        }

        return ans;
    }
};