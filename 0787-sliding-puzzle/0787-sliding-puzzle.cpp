class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string required = "123450";
        string initial = "";
        for (auto& row : board) 
            for (int num : row) 
                initial += to_string(num);
        
        if (initial == required) return 0;

        unordered_set<string> visited;
        queue<pair<string, int>> q;
        int zeroPos = initial.find('0');
        q.push({initial, zeroPos});
        visited.insert(initial);
        
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [cur, zeroPos] = q.front();
                q.pop();
                
                int x = zeroPos / 3, y = zeroPos % 3;
                for (auto& d : dir) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
                        int newPos = nx * 3 + ny;
                        string next = cur;
                        swap(next[zeroPos], next[newPos]);
                        
                        if (next == required) return moves + 1;
                        
                        if (visited.insert(next).second) {
                            q.push({next, newPos});
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
