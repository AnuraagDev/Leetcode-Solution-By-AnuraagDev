class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        set<string>a;
        backtrack(0,s,a,s.length());
        return vector<string>(a.begin(),a.end());
    }
    void backtrack(int ind,string& s,set<string>&a,int n){
        if(ind>=n){
            a.insert(s);
            return;
        }
      
            if(isdigit(s[ind]))backtrack(ind+1,s,a,n);
        
        else{
            s[ind]=toupper(s[ind]);
            backtrack(ind+1,s,a,n);
            s[ind]=tolower(s[ind]);
            backtrack(ind+1,s,a,n);
        }
    }
};