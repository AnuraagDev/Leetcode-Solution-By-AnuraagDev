class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum)return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(3*sum+1,-1));
        return solve(0,nums,target,sum,dp);
    }
    int solve(int i,vector<int>&nums,int target,int of,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(target==0)return 1;
            return 0;
        }
        if(dp[i][target+of]!=-1)return dp[i][target+of];
        int include=solve(i+1,nums,target-nums[i],of,dp);
        int exclude=solve(i+1,nums,target+nums[i],of,dp);
        return dp[i][target+of]=include+exclude;
    }
};