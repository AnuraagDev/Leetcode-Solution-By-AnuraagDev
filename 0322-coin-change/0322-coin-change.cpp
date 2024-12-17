class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins,0,amount,dp);
        if(ans==INT_MAX)return -1;
        return ans;
    }
    int solve(vector<int>&nums,int i,int amount,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(i>nums.size()-1||amount<0)return INT_MAX;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int include=INT_MAX;
        if(amount>=nums[i])include=solve(nums,i,amount-nums[i],dp);
        if(include<INT_MAX)include+=1;
        int exclude=solve(nums,i+1,amount,dp);
        return dp[i][amount]=min(include,exclude);

    }
};