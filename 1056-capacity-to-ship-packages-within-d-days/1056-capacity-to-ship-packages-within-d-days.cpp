class Solution {
public:
    bool solve(vector<int>& nums, int weight, int k) {
        int days = 1;
        int currentWeight = 0;
        for (auto i : nums) {
            currentWeight += i;
            if (currentWeight > weight) {
                days++;
                currentWeight = i;
            }
        }
        return days <= k;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = 0;
        int output = -1;
        
        for (auto i : weights) {
            totalWeight += i;
        }
        
        int low = *max_element(weights.begin(), weights.end());
        int high = totalWeight;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(weights, mid, days)) {
                output = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return output;
    }
};
