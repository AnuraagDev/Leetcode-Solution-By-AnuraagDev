class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        vector<int>frontMiss=nums;
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        reverse(frontMiss.begin(),frontMiss.end());
        frontMiss.pop_back();
        vector<int>BackMiss=nums;
        BackMiss.pop_back();
        return max(solve(0,frontMiss,dp1),solve(0,BackMiss,dp2));
    }
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int include=solve(i+2,nums,dp)+nums[i];
        int exclude=solve(i+1,nums,dp);
        return dp[i]=max(include,exclude);
    }
};