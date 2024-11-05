class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j)
        {if(s[i]!=s[j])
        {return solve(i+1,j,s)||solve(i,j-1,s);}
        i++;
        j--;
        }
        return 1;
    }
    bool solve(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
};