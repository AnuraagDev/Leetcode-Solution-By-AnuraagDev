class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string a = "";
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ') {
                a += s1[i];
            } else {
                mp[a]++;
                a = "";
            }
        }
        mp[a]++;
        a = "";
       
        vector<string> ans;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] != ' ') { 
                a += s2[i];
            } else {
                mp[a]++;
                a = "";
            }
        }
        mp[a]++; 

        for (auto &p : mp) {
            if (p.second == 1) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
