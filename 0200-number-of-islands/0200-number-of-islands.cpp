class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    solve(i,j,grid);
                }
            }
        }
        return count;
    }
    void solve(int i,int j,vector<vector<char>>&grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0')return;
        grid[i][j]='0';
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
    }
};