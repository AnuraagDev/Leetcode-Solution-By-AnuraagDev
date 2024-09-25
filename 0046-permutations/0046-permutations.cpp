class Solution {
public:set<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
    void solve(int i,vector<int>&nums){
        if(i>=nums.size()){
            ans.insert(nums);
        }
        for(int ind=i;ind<nums.size();ind++){
            swap(nums[i],nums[ind]);
            solve(i+1,nums);
             swap(nums[i],nums[ind]);
            solve(i+1,nums);
        }
    }
};