class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<bool>mark(nums.size(),0);
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;for(int i=0;i<nums.size();i++){
    pq.push({nums[i],i});
}
long long score=0;
while(!pq.empty()){
    auto d=pq.top();
    pq.pop();
    int n=d.second;
    int sum=d.first;
   if (!mark[n]) {
    score += sum;
    int a = n - 1;
    int b = n + 1;
    if (a >= 0) mark[a] = 1;
    if (b < nums.size()) mark[b] = 1;
}
}
return score;
    }
};