class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)return 0;
        int ans=INT_MAX;
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));

        for(int i=1;i<n-1;i++){
            int lefti=left(i-1,nums,i,dp1);
            int righti=right(i+1,nums,i,dp2);
            if(lefti&&righti)ans=min(ans,n-(lefti+righti+1));
        }
        return ans;
    }
    int left(int i,vector<int>&nums,int prev,vector<vector<int>>&dp){
        if(i<=-1)return 0;
        int taken=0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        if(nums[i]<nums[prev])taken=1+left(i-1,nums,i,dp);
        int untaken=left(i-1,nums,prev,dp);
        return dp[i][prev]=max(taken,untaken);
    }
      int right(int i,vector<int>&nums,int prev,vector<vector<int>>&dp){
        if(i>=nums.size())return 0;
        int taken=0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        if(nums[i]<nums[prev])taken=1+right(i+1,nums,i,dp);
        int untaken=right(i+1,nums,prev,dp);
        return dp[i][prev]=max(taken,untaken);
    }

};