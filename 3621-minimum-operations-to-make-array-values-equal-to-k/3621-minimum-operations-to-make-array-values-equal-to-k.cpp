class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &i:nums)mp[i]=1;
        int smallest=INT_MAX;
        for(auto &i:nums){
            smallest=min(i,smallest);
        }
        if(k>smallest)return -1;
        int ans=mp.size();
        if(k==smallest)return ans-1;
        return ans;
    }
};