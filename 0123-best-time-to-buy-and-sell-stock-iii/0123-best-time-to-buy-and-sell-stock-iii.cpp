class Solution {
public:
    int maxProfit( vector<int>& prices) {
        int k=2;
       vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2, -1)));

        return solve(0,prices,k,0,dp);
    }
    int solve(int i,vector<int>&prices,int k,bool take,  vector<vector<vector<int>>>&dp){
        if(k==0||i>=prices.size()){
            return 0;
        }
        if(dp[i][k][take]!=-1)return dp[i][k][take];
        int include=0;
        int exclude=0;
        if(!take){
            include=solve(i+1,prices,k,!take,dp)-prices[i];
            exclude=solve(i+1,prices,k,take,dp);
        }
        else{
             include=solve(i+1,prices,k-1,!take,dp)+prices[i];
            exclude=solve(i+1,prices,k,take,dp);
        }
        return dp[i][k][take]=max(include,exclude);
    }
};