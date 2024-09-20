class Solution {
public:
 int lps[100001];
    void kmp(string& s) {
        memset(lps,0,sizeof(lps));
        int len=0;
       const int n=s.size();
        for(int i=1;i<n;i++){
            while(len>0&&s[i]!=s[len])len=lps[len-1];
            lps[i]=(s[i]==s[len])?++len:len;
        }
    }
    string shortestPalindrome(string s) {
      string rev=string(s.rbegin(),s.rend());
      string pattern=s+"@"+rev;
      kmp(pattern);
      int Len=lps[pattern.size()-1];
      return rev.substr(0,s.size()-Len)+s;  
    }
};