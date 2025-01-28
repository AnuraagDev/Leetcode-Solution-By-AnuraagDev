class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                 
                    ans=max(ans,solve(i,j,grid));
                }
            }
        }
        return ans;
    }
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)return 0;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int ans=grid[i][j];
       grid[i][j]=0;
        for(int ind=0;ind<4;ind++){
            ans+=solve(i+dir[ind][0],j+dir[ind][1],grid);
        }
        return ans;
    }
};