class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        set<string>su;
        solve(0,s,su);
        return vector<string>(su.begin(),su.end());
    }
    void solve(int i,string& s,set<string>&su){
        if(i==s.length()){
            su.insert(s);return;
        }
        if(isdigit(s[i])){
            solve(i+1,s,su);
        }
        else{
            s[i]=tolower(s[i]);
            solve(i+1,s,su);
            s[i]=toupper(s[i]);
            solve(i+1,s,su);
        }
    }
};