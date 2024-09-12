class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = words.size();
        unordered_set<char> set(allowed.begin(), allowed.end());
        for (const string& word : words) {
            for (char ch : word) {
                if (set.find(ch) == set.end()) {
                    count--;
                    break;
                }
            }
        }

        return count;
    }
};