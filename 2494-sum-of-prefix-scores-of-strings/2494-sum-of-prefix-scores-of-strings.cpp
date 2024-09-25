struct Node {
    Node *links[26];
    int countPrefix = 0;
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increasePrefixCount() {
        countPrefix++;
    }

    int getPrefixCount() {
        return countPrefix;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefixCount();  
        }
        node->setEnd();
    }

    int getPrefixScore(string word) {
        Node* node = root;
        int score = 0;
        for (int i = 0; i < word.length(); i++) {
            node = node->get(word[i]);
            score += node->getPrefixCount(); 
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie tree;
        vector<int> result;

        // Insert all words into the Trie
        for (auto& word : words) {
            tree.insert(word);
        }

        for (auto& word : words) {
            result.push_back(tree.getPrefixScore(word));
        }

        return result;
    }
};
