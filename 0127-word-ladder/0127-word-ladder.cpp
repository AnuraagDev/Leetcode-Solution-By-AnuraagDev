class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     queue<pair<string,int>>q;
     unordered_set<string>st(wordList.begin(),wordList.end());
     if(st.find(endWord)==st.end())return 0;
     q.push({beginWord,1});
     st.erase(beginWord);
     while(!q.empty()){
        string word=q.front().first;
        int level=q.front().second;
        q.pop();
        if(word==endWord)return level;
        for(int i=0;i<word.length();i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    q.push({word,level+1});
                    st.erase(word);
                }

            }
            word[i]=original;
        }
     }   
     return 0;
    }
};