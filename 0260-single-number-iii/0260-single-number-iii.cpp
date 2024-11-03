class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int n = nums.size();

        int x = 0;

        vector<int>ans;

        for(auto it : nums) {
            x = x ^ it;
        }

        //find a set bit
        int ind = 0;
        for(int i = 0; i < 32; i++) {
            if(x >> i & 1 == 1) {
                ind = i;
                break;
            }
        }
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] >> ind & 1 == 1) {

                res = res ^ nums[i];

            }
        }

        ans.push_back(res);
        ans.push_back(res ^ x);

        return ans;
        


        
        
    }
};