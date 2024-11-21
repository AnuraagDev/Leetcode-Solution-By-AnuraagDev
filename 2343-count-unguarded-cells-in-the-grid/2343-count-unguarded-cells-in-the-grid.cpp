class Solution {
public:
    void solve(int x, int y, vector<vector<int>>& grid, set<pair<int, int>>& se) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int d = 0; d < 4; ++d) {
            int dx = dir[d][0];
            int dy = dir[d][1];
            int i = x, j = y;
            
            while (true) {
                i += dx;
                j += dy;
                
             
                if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) break;
                
                grid[i][j] = 2; 
            }
        }
    }
    
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        set<pair<int, int>> se;
        
        for (auto& g : guards) {
            grid[g[0]][g[1]] = 1; 
        }
        for (auto& w : walls) {
            grid[w[0]][w[1]] = 1; 
            se.insert({w[0], w[1]});
        }

        for (auto& g : guards) {
            solve(g[0], g[1], grid, se);
        }
        
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) count++; 
            }
        }
        return count;
    }
};
