class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>>atl(row,vector<bool>(col,0));
        vector<vector<bool>>pac(row,vector<bool>(col,0));
        for(int i=0;i<row;i++){
            solve(i,0,-1,grid,pac);
            solve(i,col-1,-1,grid,atl);
        }
        for(int i=0;i<col;i++){
            solve(0,i,-1,grid,pac);
            solve(row-1,i,-1,grid,atl);
        }
        vector<vector<int>>ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pac[i][j]&&atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }return ans;

    }
    void solve(int i,int j, int prev,vector<vector<int>>&grid,vector<vector<bool>>&visited){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())return;
        if(prev>grid[i][j])return;
        if(visited[i][j])return;
        visited[i][j]=1;
        solve(i+1,j,grid[i][j],grid,visited);
        solve(i-1,j,grid[i][j],grid,visited);
        solve(i,j+1,grid[i][j],grid,visited);
        solve(i,j-1,grid[i][j],grid,visited);

    }
};