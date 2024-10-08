class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int include=solve(i+2,nums,dp)+nums[i];
        int exclude=solve(i+1,nums,dp);
        return dp[i]= max(include,exclude);
    }
};