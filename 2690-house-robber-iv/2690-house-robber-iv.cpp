class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=(l+r)/2;
            int a=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid){
                    a++;
                    i++;
                }
            }
            if(a>=k)r=mid;
            else l=mid+1;
        }
        return l;
    }
};