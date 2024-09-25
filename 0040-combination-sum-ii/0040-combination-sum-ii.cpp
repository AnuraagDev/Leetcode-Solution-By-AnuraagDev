class Solution {
public:set<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        vector<int>a;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,a,target,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
    void solve(vector<int>&nums,int i,vector<int>&a,int required,int sum){
        if(i>=nums.size()||sum>=required){
            if(sum==required){   
                ans.insert(a);
            }
            return;
        }
        a.push_back(nums[i]);
        solve(nums,i+1,a,required,sum+nums[i]);
        a.pop_back();
        while(i<nums.size()-1&&nums[i]==nums[i+1])i++;
        solve(nums,i+1,a,required,sum);
    }

};