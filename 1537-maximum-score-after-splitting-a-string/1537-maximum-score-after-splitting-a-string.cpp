class Solution {
public:
    int maxScore(string s) {
        vector<int>right(s.length(),0);
        vector<int>left(s.length(),0);
        int j=0;
        if(s[0]!='0')right[0]=0;
        else right[0]=1;
        for(int i=1;i<s.length();i++){
            right[i]=right[i-1];
            if(s[i]=='0')right[i]++;
        }
        if(s[s.length()-1]=='1')left[s.length()-1]=1;
        else left[s.length()-1]=0;
        for(int i=s.length()-2;i>=0;i--){
            left[i]=left[i+1];
            if(s[i]=='1')left[i]++;
        }
        int maxi=0;
        for(int i=0;i<s.length()-1;i++){
            maxi=max(maxi,left[i+1]+right[i]);
        }
return maxi;
    }
};