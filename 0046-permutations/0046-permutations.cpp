class Solution {
public:vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>freq(nums.size(),0);
        vector<int>d;
        solve(freq,nums,d);
        return ans;
    }
    void solve(vector<int>&frq,vector<int>&nums,vector<int>&d){
        if(d.size()==nums.size()){
            ans.push_back(d);
            return;
        }
        for(int ind=0;ind<nums.size();ind++){
            if(!frq[ind]){
                frq[ind]=1;
                d.push_back(nums[ind]);
                solve(frq,nums,d);
                d.pop_back();
                frq[ind]=0;
            }
        }
    }
};