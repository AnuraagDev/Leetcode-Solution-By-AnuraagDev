class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int res = 0;
        for (char a = 'a'; a <= 'z'; ++a) {
            int l = 0, r = n - 1;
            while (l < n && s[l] != a) ++l;
            while (r >= 0 && s[r] != a) --r;
            if (l < r) {
                vector<bool> seen(26, false);
                for (int i = l + 1; i < r; ++i) {
                    seen[s[i] - 'a'] = true;
                }
                res += count(seen.begin(), seen.end(), true);
            }
        }
        return res;
    }
};
