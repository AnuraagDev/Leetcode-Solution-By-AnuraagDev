class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(n,k,row,column,dp);
    }
    double solve(int n,int k,int row, int col,vector<vector<vector<double>>>&dp){
        if(k==0)return 1;
        int dir[8][2]={{2,-1},{2,1},{-2,-1},{-2,+1},{-1,2},{1,2},{-1,-2},{1,-2}};
        double ans=0;
        if(dp[row][col][k]!=-1)return dp[row][col][k];
        for(int i=0;i<8;i++){
        int new_x=dir[i][0]+row;
        int new_y=dir[i][1]+col;
        if(new_x>=n||new_x<0||new_y>=n||new_y<0)continue;
        ans+=solve(n,k-1,new_x,new_y,dp);
        }
        return dp[row][col][k]=ans/8.0;
    }
};