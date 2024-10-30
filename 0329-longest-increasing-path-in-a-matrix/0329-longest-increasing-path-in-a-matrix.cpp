class Solution {
public:
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int maxi=0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            maxi=max(maxi,bfs(i,j,matrix,dp));
        }
    }    
    return maxi;
    }
    int bfs(int x,int y,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(dp[x][y]!=-1)return dp[x][y];
        int maxi=1;
        for(int i=0;i<4;i++){
            int new_x=x+dirs[i][0];
            int new_y=y+dirs[i][1];
            if(new_x<0||new_y<0||new_x>=matrix.size()||new_y>=matrix[0].size()||matrix[new_x][new_y]<=matrix[x][y])continue;
            int len=1+bfs(new_x,new_y,matrix,dp);
            maxi=max(len,maxi);
        }
        return dp[x][y]=maxi;
        
    }
};