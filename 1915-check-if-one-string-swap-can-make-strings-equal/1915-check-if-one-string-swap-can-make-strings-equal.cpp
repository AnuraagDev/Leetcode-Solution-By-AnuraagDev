class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        int x=-1,y=-1;
        int c=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(c==0){
                    x=i;
                }else{
                    y=i;
                }
                c++;
            }
        }
        if(c==2){
            return s1[x]==s2[y] && s2[x]==s1[y];
        }
        return c==0;
    }
};