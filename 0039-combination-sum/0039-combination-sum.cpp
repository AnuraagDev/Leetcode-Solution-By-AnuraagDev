class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>a;
        solve(0,0,candidates,target,a);
        return ans;
    }
    void solve(int i,int sum,vector<int>&candidates,int target,vector<int>&a){
        if(target<=sum||i>=candidates.size()){
            if(target==sum)
            ans.push_back(a);
            return;
        }
        a.push_back(candidates[i]);
        solve(i,sum+candidates[i],candidates,target,a);
        a.pop_back();
        solve(i+1,sum,candidates,target,a);

    }
};