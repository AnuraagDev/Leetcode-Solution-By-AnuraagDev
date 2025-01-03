class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long left=0; long long right=0;
        for(auto i:nums)right+=i;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            right-=nums[i];
            if(left>=right)count++;
        }
        return count;
    }
};