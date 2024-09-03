class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1;
        int suf=1;
        int ans=INT_MIN;
       
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            
            pre*=nums[i];
            suf*=nums[n-i-1];
            int temp=pre;
            temp=max({temp,pre,suf});
            ans=max(temp,ans);
        }
        return ans;
    }
};