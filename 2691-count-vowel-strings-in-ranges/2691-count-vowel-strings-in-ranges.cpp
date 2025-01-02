class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>se;
        string vowels="aeiou";
        for(auto i:vowels)se.insert(i);
        vector<int>pre(words.size()+1);
         int count;
        for(int i=0;i<words.size();i++){
            
           pre[i+1]=pre[i];
           if(se.count(words[i].front())&&se.count(words[i].back()))pre[i+1]++;
        }
        vector<int>ans;
        for(auto &d:queries){
            int i=d[0];
            int j=d[1];
           
                ans.push_back(pre[j+1]-pre[i]);
            
           
        }
        return ans;
    }
};