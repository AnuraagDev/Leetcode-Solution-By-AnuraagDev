class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,prices,0,dp);
    }
    int solve(int i,vector<int>&prices,bool take,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][take]!=-1)return dp[i][take];
        int include=0;
        int exclude=0;
        if(!take){
            include=solve(i+1,prices,!take,dp)-prices[i];
            exclude=solve(i+1,prices,take,dp);
        }
        else{
            include=prices[i]+solve(i+2,prices,!take,dp);
            exclude=solve(i+1,prices,take,dp);
        }
        return dp[i][take]= max(include,exclude);
    }
};