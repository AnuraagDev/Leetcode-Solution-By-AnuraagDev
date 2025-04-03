class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size()+1,-1);
        return solve(0,questions,dp);
    }
    long long solve(int i,vector<vector<int>>&arr,vector<long long>&dp){
    if(i>=arr.size())return 0;
    if(dp[i]!=-1)return dp[i];
    long long include=solve(i+arr[i][1]+1,arr,dp)+arr[i][0];
    long long exclude=solve(i+1,arr,dp);
        return dp[i]=max(include,exclude);
    }
};