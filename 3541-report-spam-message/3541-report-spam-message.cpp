#include <unordered_set>
#include <vector>
#include <string>

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());
        int count = 0;
        int newSize = 0;
        
        for (int i = 0; i < message.size(); ++i) {
            if (bannedSet.find(message[i]) != bannedSet.end()) {
                count++;
            } else {
                message[newSize++] = message[i];
            }
        }
        message.resize(newSize);
        
        return count >= 2;
    }
};
