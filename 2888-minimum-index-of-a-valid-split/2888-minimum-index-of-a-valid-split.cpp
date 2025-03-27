class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int ele=nums[0],count=0,total=0;
        for(auto &i:nums){
            if(i==ele) count++;
            else count--;
            if(count==0){ ele=i; count=1; }
        }
        for(auto &i:nums){
            if(i==ele) total++;
        }
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele) count++;
            int remaining=total-count;
            if(count*2>i+1 && remaining*2>n-i-1) return i;
        }
        return -1;
    }
};
