class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>fres1(26,0);
        vector<int>fres2(26,0);
        if(s1.length()>s2.length())return 0;
        for(int i=0;i<s1.length();i++){
            fres1[s1[i]-'a']++;
            fres2[s2[i]-'a']++;
        }
        for(int i=0;i<s2.length()-s1.length();i++){
            if(fres1==fres2)return 1;
            fres2[s2[i]-'a']--;
            fres2[s2[i+s1.length()]-'a']++;
        }
        return fres1==fres2;




    }
};