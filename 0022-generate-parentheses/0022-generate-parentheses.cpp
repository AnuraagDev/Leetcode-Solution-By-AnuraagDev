class Solution {
public:
vector<string>ans;
    vector<string> generateParenthesis(int n) {
        solve("",0,0,n);
        return ans;
    }
    void solve(string s,int left,int right,int n){
        if(left==n&&left==right&&(left+right==n*2)){
            ans.push_back(s);
            return;
        }
        if(left<n)solve(s+"(",left+1,right,n);
        if(right<left)solve(s+")",left,right+1,n);
    }
};