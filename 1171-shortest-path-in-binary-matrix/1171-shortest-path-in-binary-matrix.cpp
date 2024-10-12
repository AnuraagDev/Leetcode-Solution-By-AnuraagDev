class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n=grid.size();
            if(grid[0][0]||grid[n-1][n-1])return -1;
            if(grid.size()==1)return 1;
            queue<pair<int,pair<int,int>>>q;
            q.push({0,{0,0}});
            int dir[8][2]={{0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}};
            int ans=0;
            vector<vector<int>>visited(n,vector<int>(n,0));
            visited[0][0]=1;
            while(!q.empty()){
                int distance=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();
                if(x==n-1&&y==n-1)return distance+1;
                for(int i=0;i<8;i++){
                    int new_x=x+dir[i][0];
                    int new_y=y+dir[i][1];
                    if(isValid(new_x,new_y,grid,visited)){
                        q.push({distance+1,{new_x,new_y}});
                        visited[new_x][new_y]=1;
                    }
                }
            }
            return -1;
        }
        bool isValid(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited){int n=grid.size();
            return i>=0&&j>=0&&i<=n-1&&j<=n-1&&grid[i][j]==0&&!visited[i][j];
        }
};