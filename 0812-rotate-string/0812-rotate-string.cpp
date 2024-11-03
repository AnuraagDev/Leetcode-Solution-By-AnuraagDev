class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return 0;
        string temp=s+s;
        int count=0;
         return (temp.find(goal) != string::npos);
    }
};