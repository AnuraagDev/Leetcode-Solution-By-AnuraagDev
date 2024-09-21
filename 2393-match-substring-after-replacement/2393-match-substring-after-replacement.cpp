class Solution {
public:
    bool isMatch(string& s,string &sub,vector<vector<int>>&mp){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=sub[i]){
                char oldi=sub[i],newi=s[i];
                if(!mp[oldi][newi])return false;
            }
        }return 1;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<int>>mp(256,vector<int>(256,0));
        int n=s.size(),m=sub.size();
        for(auto it:mappings){
            char oldi=it[0],newi=it[1];
            mp[oldi][newi]=1;
        }
        for(auto i=0;(i+m)<=n;i++){
            string temp=s.substr(i,m);
            if(isMatch(temp,sub,mp))return true;
        }return false;
    }
};