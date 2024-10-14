class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto i:nums){
            q.push(i);
        }
        long long ans=0;
        while(k!=0){
            int d=q.top();
            q.pop();
            ans+=d;
            d=ceil((double)d/3);
            q.push(d);
            k--;
        }
        return ans;
    }
};