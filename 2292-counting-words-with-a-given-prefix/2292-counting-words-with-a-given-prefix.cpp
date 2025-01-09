class Solution {
public:
    bool ifmatch(string a,string b){
        for(int i=0;i<b.length();i++){
            if(a[i]!=b[i])return 0;
        }
        return 1;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto i:words){
            if(ifmatch(i,pref))count++;
        }
        return count;
    }
};