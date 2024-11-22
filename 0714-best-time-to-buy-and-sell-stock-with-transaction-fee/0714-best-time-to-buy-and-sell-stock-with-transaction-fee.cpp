class Solution {
public:
    int maxProfit(vector<int>& prices,int fees) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,prices,0,dp,fees);
    }
    int solve(int i,vector<int>&prices,bool take,vector<vector<int>>&dp,int fees){
        if(i>=prices.size())return 0;
        if(dp[i][take]!=-1)return dp[i][take];
        int include=0;
        int exclude=0;
        if(!take){
            include=solve(i+1,prices,!take,dp,fees)-(fees+prices[i]);
            exclude=solve(i+1,prices,take,dp,fees);
        }
        else{
            include=prices[i]+solve(i+1,prices,!take,dp,fees);
            exclude=solve(i+1,prices,take,dp,fees);
        }
        return dp[i][take]= max(include,exclude);
    }
};