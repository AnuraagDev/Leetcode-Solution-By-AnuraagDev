class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
       long long int ans=-1;
        int mod=1e9+7;
        solve(0,0,grid,1,ans);
        return ans%mod;
        }
        void solve(int i,int j,vector<vector<int>>&grid,long long curr,long long &ans){
            if(grid[i][j]==0){
                ans=max(ans,0LL);
                return;
            }
            curr*=grid[i][j];
            if(i==grid.size()-1&&j==grid[0].size()-1){
                ans=max(ans,curr);
                return;
            }
            if(i+1<grid.size())solve(i+1,j,grid,curr,ans);
           if(j+1<grid[0].size())solve(i,j+1,grid,curr,ans);
        }
        
};