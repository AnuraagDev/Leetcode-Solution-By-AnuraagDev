#define pii pair<int,int>
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
         for(int i=0;i<nums.size();i++){
            pq.emplace(nums[i],i);
         }
         while(k--){
            auto [x,i]=pq.top();
            pq.pop();
            pq.emplace(multiplier*x,i);
         }
         while(!pq.empty()){
            auto [x,i]=pq.top();
            pq.pop();
            nums[i]=x;
         }
         return nums;
    }
};