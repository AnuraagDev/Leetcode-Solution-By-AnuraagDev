class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int res = 0;
        for (char a = 'a'; a <= 'z'; ++a) {
            int l = 0, r = n - 1;
            while (l < n && s[l] != a)
                ++l; // check for the first occurence
            while (r >= 0 && s[r] != a)
                --r; // check for the last occurence
            if (l < r) {
                vector<bool> seen(26, false);
                for (int i = l + 1; i < r; ++i) {
                    seen[s[i] - 'a'] =
                        true; // check for all different alpha available for
                              // purpose of unique calculation
                }
                res += count(seen.begin(), seen.end(), true);
            }
        }
        return res;
    }
};
