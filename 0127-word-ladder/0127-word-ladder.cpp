class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;

        unordered_set<string>se(wordList.begin(),wordList.end());
        if(se.find(endWord)==se.end())return 0;
        q.push({beginWord,1});
        se.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord)return step;
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(se.find(word)!=se.end()){
                        q.push({word,step+1});
                        se.erase(word);
                    }

                }
                word[i]=original;
            }
        }
        return 0;
    }
};