class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto [cost, cell] = pq.top();
            pq.pop();
            int x = cell.first;
            int y = cell.second;
            if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) continue;
            vis[x][y] = 1;
            if (x == n - 1 && y == m - 1) return cost;
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i].first;
                int ny = y + directions[i].second;
                int newCost = cost + (grid[x][y] == i + 1 ? 0 : 1);
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    pq.push({newCost, {nx, ny}});
                }
            }
        }

        return 0;
    }
};
