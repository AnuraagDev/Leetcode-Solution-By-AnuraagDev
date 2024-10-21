class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>se;
        vector<int>dp(s.size(),-1);
        return solve(0,s,se,dp);
        
        }
        int solve(int i,string &s,unordered_set<string>&se,vector<int>&dp){
            if(i==s.size())return 0;
          //  if(dp[i]!=-1)return dp[i];
        int maxi=0;
        for(int ind=i+1;ind<=s.size();ind++){
            string sub=s.substr(i,ind-i);
            if(se.find(sub)==se.end()){
                se.insert(sub);
                maxi=max(maxi,1+solve(ind,s,se,dp));
                se.erase(sub);
            }}
            return  maxi;
        }
};