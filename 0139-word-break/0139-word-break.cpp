class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        return solve(0,dict,s,dp);
    }
    bool solve(int i,unordered_set<string>dict,string &s,vector<int>&dp){
        if(i>=s.length())return 1;
        if(dp[i]!=-1)return dp[i];
        if(dict.find(s)!=dict.end())return dp[i]=1;
        for(int j=1;j<=s.length()-i;j++){
            string temp=s.substr(i,j);
            if(dict.find(temp)!=dict.end()&&solve(i+j,dict,s,dp))return dp[i]= 1;
        }
        return dp[i]=0;
    }
};