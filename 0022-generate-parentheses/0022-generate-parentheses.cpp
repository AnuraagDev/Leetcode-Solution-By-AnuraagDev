class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,ans,"",n);
        return ans;
    }
    void solve(int left,int right,vector<string>&ans,string a,int n){
        if(a.length()==n*2){
            ans.push_back(a);
            return;
        }
        if(left<n)solve(left+1,right,ans,a+'(',n);
        if(left>right)solve(left,right+1,ans,a+')',n);
    }
};