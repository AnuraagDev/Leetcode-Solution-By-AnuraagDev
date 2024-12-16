class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
       return solve(0,0,text1,text2,dp);
    }
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i>s1.size()-1||j>s2.size()-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]= 1+solve(i+1,j+1,s1,s2,dp);
        int left=solve(i+1,j,s1,s2,dp);
        int right=solve(i,j+1,s1,s2,dp);
        return dp[i][j]=max(left,right);
    }
};