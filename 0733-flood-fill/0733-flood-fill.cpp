class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start=image[sr][sc];
        queue<pair<int,int>>q;
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            auto d=q.front();
            q.pop();
            int x=d.first;
            int y=d.second;
            visited[x][y]=1;
            for(int i=0;i<4;i++){
                int new_x=x+dir[i][0];
                int new_y=y+dir[i][1];
                if(valid(new_x,new_y,start,image,visited)){
                    image[new_x][new_y]=color;
                    q.push({new_x,new_y});
                }
            }

        }
        return image;
    }
    bool valid(int x,int y,int start,vector<vector<int>>&grid,vector<vector<int>>&visited){
        return (x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]==start&&visited[x][y]==0);
    }
};