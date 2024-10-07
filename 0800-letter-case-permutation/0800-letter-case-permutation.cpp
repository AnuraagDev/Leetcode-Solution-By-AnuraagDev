class Solution {
public:
    vector<string> letterCasePermutation(string s) {
     set<string>ans;
     solve(0,ans,s);   
     return vector<string>(ans.begin(),ans.end());
    }
    void solve(int i,set<string>&ans,string &s){
        if(i==s.length()){
            ans.insert(s);
            return;
        }
        if(isdigit(s[i]))solve(i+1,ans,s);
        s[i]=toupper(s[i]);
        solve(i+1,ans,s);
        s[i]=tolower(s[i]);
        solve(i+1,ans,s);
    }
};