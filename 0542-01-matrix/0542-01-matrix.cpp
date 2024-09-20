class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX-1));
        queue<pair<int, int>> q;
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;
                
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                
                    if (ans[newX][newY] > ans[x][y] + 1) {
                        ans[newX][newY] = ans[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        
        return ans;
    }
};
