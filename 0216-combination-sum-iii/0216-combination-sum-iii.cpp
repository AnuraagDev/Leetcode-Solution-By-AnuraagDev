class Solution {
public:
vector<vector<int>>an;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        for(auto i=1;i<=9;i++){
            ans.push_back(i);
        }
        vector<int>a;
        solve(0,ans,a,k,n);
        return an;
    }
    void solve(int i,vector<int>&a,vector<int>&d,int k,int n){
        if(i>8||d.size()>=k){
            if(d.size()==k&&n==0){
                an.push_back(d);
                return;
            }
            return;
        }
        d.push_back(a[i]);
        solve(i+1,a,d,k,n-a[i]);
        d.pop_back();
        solve(i+1,a,d,k,n);

    }
};