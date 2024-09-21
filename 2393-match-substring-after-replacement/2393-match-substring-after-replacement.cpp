class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<int>>mp(256,vector<int>(256,0));
        int n=s.size(),m=sub.size();
        for(auto i:mappings){
            char a=i[0],b=i[1];
            mp[a][b]=1;
        }
        for(int i=0;i+m<=n;i++){
            string temp=s.substr(i,m);
            if(solve(temp,sub,mp))return true;

        }return false;
    }
    bool solve(string &s,string &sub,vector<vector<int>>&mp){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=sub[i]){
                char a=sub[i],b=s[i];
                if(!mp[a][b])return false;
            }
        }return true;
    }
};