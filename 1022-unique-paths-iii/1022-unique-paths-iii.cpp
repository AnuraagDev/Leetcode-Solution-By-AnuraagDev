class Solution {
public:
 int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int uniquePathsIII(vector<vector<int>>& grid) {
    
        int startx=-1,starty=-1,cell=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                }
                if(!grid[i][j])cell++;
                
                
            }
        }
        return dfs(startx,starty,grid,cell+1);
    }
    int dfs(int i,int j,vector<vector<int>>&grid,int cell){
        if(i<0||j<0||i>grid.size()-1||j>grid[0].size()-1||grid[i][j]==-1||grid[i][j]==3)return 0;
        if(grid[i][j]==2) return cell == 0 ? 1 : 0;
        grid[i][j]=3;
        int ans=0;
        for(int k=0;k<4;k++){
            ans+=dfs(i+dir[k][0],j+dir[k][1],grid,cell-1);
        }
        grid[i][j]=0;
        return ans;
    }
};