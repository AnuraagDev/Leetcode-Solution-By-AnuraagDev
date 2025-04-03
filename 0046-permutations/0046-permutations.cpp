class Solution {
public:
vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>se;
        vector<int>s;
        solve(se,nums,s);
        return ans;
    }
    void solve(unordered_set<int>&se,vector<int>&nums,vector<int>&a){
        if(a.size()==nums.size()){
            ans.push_back(a);
            return;
        }
       for(int i=0;i<nums.size();i++){ if(!se.count(nums[i])){
            se.insert(nums[i]);
            a.push_back(nums[i]);
            solve(se,nums,a);
            se.erase(nums[i]);
            a.pop_back();
        }}
    }
};