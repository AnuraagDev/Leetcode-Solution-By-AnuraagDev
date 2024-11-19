class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)sum++;
            else sum=0;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};