class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k)return 0;
        vector<int>ch(26,0);
        for(auto i:s){
            ch[i-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(ch[i]%2){count++;
            }
        }
       return count>k?0:1;
    }
};