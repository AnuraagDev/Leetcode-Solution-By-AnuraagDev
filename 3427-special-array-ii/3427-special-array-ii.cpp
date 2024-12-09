class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector <int> prefix (nums.size() , 0);
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1];
            if(nums[i]%2==nums[i-1]%2)prefix[i]++;
        }
    
    vector<bool>ans;
     for(auto q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
        }
        return ans;}
};