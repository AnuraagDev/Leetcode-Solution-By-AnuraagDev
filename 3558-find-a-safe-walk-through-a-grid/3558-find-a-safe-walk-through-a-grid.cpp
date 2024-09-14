#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        if (m == 0) return false; // Edge case for empty grid
        int n = grid[0].size();
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        queue<pair<int, int>> q;
        int starting_health = health - grid[0][0]; // Deduct the health cost from starting point
        
        if (starting_health <= 0) return false; // Can't proceed if health becomes 0 or negative at start
        q.push({0, 0});
        visited[0][0] = starting_health;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int curr_health = visited[x][y];
            
            if (x == m - 1 && y == n - 1 && curr_health > 0) {
                return true;
            }
            
            for (auto dir : directions) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;
                
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    int new_health = curr_health - grid[new_x][new_y];
                    
                    if (new_health > 0 && new_health > visited[new_x][new_y]) {
                        visited[new_x][new_y] = new_health;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        
        return false;
    }
};
