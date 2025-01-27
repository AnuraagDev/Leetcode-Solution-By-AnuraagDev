class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>a;
        vector<vector<int>>ans;
        solve(0,a,ans,nums);
        return ans;
    }
    void solve(int i,vector<int>&a,vector<vector<int>>&ans,vector<int>&nums){
        if(i>=nums.size()){
            ans.push_back(a);
            return;
        }
        a.push_back(nums[i]);
        solve(i+1,a,ans,nums);
        a.pop_back();
        solve(i+1,a,ans,nums);
    }
};