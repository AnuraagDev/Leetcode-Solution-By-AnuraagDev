class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> mp(nums.begin(), nums.end());
        int maxStreak = 0;

        for (auto i : nums) {
            maxStreak = max(maxStreak, solve(i, mp));
        }

        return maxStreak == 1 ? -1 : maxStreak;
    }

private:
    int solve(long long i, unordered_set<long long>& mp) {
        if (mp.find(i * i) != mp.end()) {
            return 1 + solve(i * i, mp);
        }
        return 1; 
    }
};
