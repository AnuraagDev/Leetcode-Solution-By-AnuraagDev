class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) { 
        int n = heights.size();
        if (n == 0) return {};
        int m = heights[0].size();

        vector<vector<bool>> atl(n, vector<bool>(m, 0));
        vector<vector<bool>> pac(n, vector<bool>(m, 0));

        // Flow from Pacific (left and top edges)
        for (int i = 0; i < n; i++) {
            solve(i, 0, heights[i][0], heights, pac);  // Left edge
            solve(i, m - 1, heights[i][m - 1], heights, atl);  // Right edge
        }

        // Flow from Atlantic (right and bottom edges)
        for (int i = 0; i < m; i++) {
            solve(0, i, heights[0][i], heights, pac);  // Top edge
            solve(n - 1, i, heights[n - 1][i], heights, atl);  // Bottom edge
        }

        vector<vector<int>> ans;
        // Fix the loop: rows first, then columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void solve(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j]) return;
        if (grid[i][j] < prev) return;  // Compare with previous height

        visited[i][j] = true;
        // Pass grid[i][j] as the new 'prev' for the next recursive call
        solve(i + 1, j, grid[i][j], grid, visited);
        solve(i - 1, j, grid[i][j], grid, visited);
        solve(i, j + 1, grid[i][j], grid, visited);
        solve(i, j - 1, grid[i][j], grid, visited);
    }
};
