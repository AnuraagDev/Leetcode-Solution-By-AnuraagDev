class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        long long sum = 0, maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            freq[nums[i]]++;

            if (i >= k) {
                sum -= nums[i - k];
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) {
                    freq.erase(nums[i - k]);
                }
            }

            if (freq.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
