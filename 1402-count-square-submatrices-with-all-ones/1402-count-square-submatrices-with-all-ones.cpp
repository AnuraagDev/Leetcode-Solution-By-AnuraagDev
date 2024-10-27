class Solution {
public:
    int dp[300][300];
    int countSquares(vector<vector<int>>& matrix) {
        int count=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                count+=solve(i,j,matrix);
            }
           
        } return count;
    }
    int solve(int i,int j,vector<vector<int>>&matrix){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()||!matrix[i][j])return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+min({solve(i-1,j,matrix),solve(i,j-1,matrix),solve(i-1,j-1,matrix)});
    }
};