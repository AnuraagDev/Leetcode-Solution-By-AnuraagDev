class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(auto i:nums)maxOr|=i;
        int count=0;
        solve(0,maxOr,0,nums,count);
        return count;
    }
    void solve(int ind,int MaxOr,int com,vector<int>&nums,int &count){
        if(com==MaxOr){
            count++;
        }
        for(int i=ind;i<nums.size();i++){
            solve(i+1,MaxOr,com|nums[i],nums,count);
        }
    }

};