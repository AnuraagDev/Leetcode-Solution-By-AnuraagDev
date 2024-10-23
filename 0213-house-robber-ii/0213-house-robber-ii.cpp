class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>empty1=nums;
        empty1.pop_back();
        vector<int>empty2=nums;
        vector<int>dp(nums.size(),-1);
        vector<int>dp1(nums.size(),-1);

        reverse(empty2.begin(),empty2.end());
        empty2.pop_back();

        return max(solve(0,empty1,dp),solve(0,empty2,dp1));;
    }
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int include=solve(i+2,nums,dp)+nums[i];
        int exclude=solve(i+1,nums,dp);
        return dp[i]=max(include,exclude);
        
            
        }
    
};