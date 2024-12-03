class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        int spaceIndex = 0;
        string ans;
        ans.reserve(n + m);
        for (int i = 0; i < n; ++i) {
            while (spaceIndex < m && spaces[spaceIndex] == i) {
                ans += ' ';
                spaceIndex++;
            }
            ans += s[i];
        }
        while (spaceIndex < m) {
            ans += ' ';
            spaceIndex++;
        }
        
        return ans;
    }
};
