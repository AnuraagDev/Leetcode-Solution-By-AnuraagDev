class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
       solve(0,nums,ans);
       return vector<vector<int>>(ans.begin(),ans.end());
    }
    void solve(int i,vector<int>&nums,set<vector<int>>&ans){
        if(i>=nums.size()-1){
            ans.insert(nums);
            return;
        }
        for(int ind=i;ind<nums.size();ind++){
            swap(nums[i],nums[ind]);
            solve(i+1,nums,ans);
            swap(nums[i],nums[ind]);
            solve(i+1,nums,ans);
        }
    }

};