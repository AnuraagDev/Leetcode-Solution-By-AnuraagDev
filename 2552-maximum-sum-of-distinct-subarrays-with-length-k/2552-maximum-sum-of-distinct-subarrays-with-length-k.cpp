class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To track frequency of elements
        long long sum = 0, maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Add current element to the window
            sum += nums[i];
            freq[nums[i]]++;

            // Shrink the window if it exceeds size k
            if (i >= k) {
                sum -= nums[i - k];
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) {
                    freq.erase(nums[i - k]);
                }
            }

            // Check if the current window is valid and update the maximum sum
            if (freq.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
