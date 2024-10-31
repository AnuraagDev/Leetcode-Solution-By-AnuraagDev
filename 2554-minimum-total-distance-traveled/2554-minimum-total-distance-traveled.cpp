class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>fac;
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        for(auto i:factory){
            for(int j=0;j<i[1];j++){
                fac.push_back(i[0]);
            }
        }
        vector<vector<long long>>dp(robot.size(),vector<long long>(fac.size(),-1));
        return solve(0,0,robot,fac,dp);
    }
    long long solve(int i,int j, vector<int>&robot,vector<int>&fac,vector<vector<long long>>&dp){
        if(i>=robot.size())return 0;
        if(j>=fac.size())return LLONG_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        long long take=LLONG_MAX;
        take=solve(i+1,j+1,robot,fac,dp);
        if(take!=LLONG_MAX)take+=abs(robot[i]-fac[j]);
        long long notTake=solve(i,j+1,robot,fac,dp);
        return dp[i][j]=min(take,notTake);
    }
};