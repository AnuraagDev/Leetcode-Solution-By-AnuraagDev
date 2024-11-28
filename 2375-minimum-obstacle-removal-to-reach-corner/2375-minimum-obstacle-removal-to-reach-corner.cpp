class Solution {
public:
bool valid(int i,int j,vector<vector<int>>& grid){
    return i>=0&&j>=0&&i<grid.size()&&j<grid[0].size();
}
    int minimumObstacles(vector<vector<int>>& grid) {
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>distance(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        deque<pair<int,int>>q;
        q.push_front({0,0});
        distance[0][0]=0;
        while(!q.empty()){
            auto d=q.front();
            q.pop_front();
            int x=d.first;
            int y=d.second;
            int dis=distance[x][y];
            for(int i=0;i<4;i++){
                int new_x=x+dir[i][0];
                int new_y=y+dir[i][1];
                if(valid(new_x,new_y,grid)){
                    if(dis+grid[new_x][new_y]<distance[new_x][new_y]){
                        if(grid[new_x][new_y])q.push_back({new_x,new_y});
                        else q.push_front({new_x,new_y});
                        distance[new_x][new_y]=dis+grid[new_x][new_y];
                    }
                }
            }
        }
        return distance[grid.size()-1][grid[0].size()-1];
    }
};