class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>se(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        if(se.find(endWord)==se.end())return 0;
        q.push({beginWord,1});
        se.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            if(word==endWord)return step;
            q.pop();
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(se.find(word)!=se.end()){
                        q.push({word,step+1});
                        se.erase(word);
                    }

                }word[i]=original;
            }
        }
        return 0;
    }
};