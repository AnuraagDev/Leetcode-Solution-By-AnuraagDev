class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({headID, 0});
        int maxTime = 0;

        while (!q.empty()) {
            auto [curr, time] = q.front();
            q.pop();
            maxTime = max(maxTime, time);
            for (int child : adj[curr]) {
                q.push({child, time + informTime[curr]});
            }
        }

        return maxTime;
    }
};
