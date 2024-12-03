class Solution {
public:
    vector<string> ans;
    unordered_map<int, vector<string>> memo; 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        string a = "";
        solve(0, s, a, dict);
        return memo[0];
    }

    void solve(int ind, string& s, string a, unordered_set<string>& dict) {
        if (memo.count(ind)) {
            for (const string& str : memo[ind]) {
                ans.push_back(a.empty() ? str : a + " " + str);
            }
            return;
        }

        if (ind >= s.length()) {
            if (ind == s.length()) {
                ans.push_back(a);
                memo[ind].push_back(""); 
            }
            return;
        }

        vector<string> results; 
        for (int j = ind; j <= s.length(); j++) {
            string temp = s.substr(ind, j - ind + 1);
            if (dict.find(temp) != dict.end()) {
                string newA = a.empty() ? temp : a + " " + temp;
                vector<string> subResults; 
                if (memo.count(j + 1)) {
                    subResults = memo[j + 1];
                } else {
                    solve(j + 1, s, "", dict);
                    subResults = memo[j + 1];
                }
                for (const string& sub : subResults) {
                    string fullResult = temp + (sub.empty() ? "" : " " + sub);
                    results.push_back(fullResult);
                }
            }
        }

        memo[ind] = results;
        if (a.empty()) {
            for (const string& res : results) {
                ans.push_back(res);
            }
        }
    }
};
