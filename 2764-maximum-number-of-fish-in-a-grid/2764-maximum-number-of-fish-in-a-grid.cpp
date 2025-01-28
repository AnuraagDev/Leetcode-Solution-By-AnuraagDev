class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
                    ans=max(ans,solve(i,j,grid,visited));
                }
            }
        }
        return ans;
    }
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0||visited[i][j])return 0;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int ans=grid[i][j];
       
        visited[i][j]=1;
        for(int ind=0;ind<4;ind++){
            ans+=solve(i+dir[ind][0],j+dir[ind][1],grid,visited);
        }
        return ans;
    }
};