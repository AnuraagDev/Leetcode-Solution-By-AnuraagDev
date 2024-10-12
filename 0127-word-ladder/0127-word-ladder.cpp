class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;

        unordered_set<string>se(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord)return step;
            se.erase(word);
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(se.find(word)!=se.end()){
                        q.push({word,step+1});
                    }

                }
                word[i]=original;
            }
        }
        return 0;
    }
};