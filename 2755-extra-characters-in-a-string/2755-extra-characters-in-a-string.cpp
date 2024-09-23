class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>d(dictionary.begin(),dictionary.end());
        vector<int>dp(s.length(),-1);
        return solve(0,s,d,dp);
    }
    int solve(int i,string& a,unordered_set<string>&d, vector<int>&dp)
{
    if(i>=a.size()){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
string temp="";
    int extra=INT_MAX;
    for(int ind=i;ind<a.length();ind++){
        temp+=a[ind];
        if(d.find(temp)!=d.end()){
            extra=min(extra,solve(ind+1,a,d,dp));
        }

        }
       
      extra=min(extra,1+solve(i+1,a,d,dp));   
    return dp[i]= extra;}

};