class Solution {
public:
int dp[1000];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0,arr,k);
    }
    int solve(int i,vector<int>&arr,int k){
        if(i>arr.size()-1)return 0;
        int ans=0;
        if(dp[i]!=-1)return dp[i];
        int curr_max=INT_MIN;
        int curr=0;
        for(int ind=i;ind<min((int)arr.size(),i+k);ind++){
            curr_max=max(curr_max,arr[ind]);
            curr=(ind-i+1)*curr_max;
            ans=max(ans,curr+solve(ind+1,arr,k));
        }
        return dp[i]=ans;

    }
};