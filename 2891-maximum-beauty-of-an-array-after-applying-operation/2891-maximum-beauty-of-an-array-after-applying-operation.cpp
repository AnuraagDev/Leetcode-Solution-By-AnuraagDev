class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxBeauty = 1;
        for (int i = 0; i < n; i++) {
            int ub = find(nums, nums[i] + 2 * k);
            maxBeauty = max(maxBeauty, ub - i + 1);
        }
    
    return maxBeauty;
} int find(const vector<int>& nums, int val) {
    int l = 0, r = nums.size() - 1, res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= val) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}
}
;