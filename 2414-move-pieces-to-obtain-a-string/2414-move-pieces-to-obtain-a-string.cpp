class Solution {
public:
    bool canChange(string start, string target) {
        int i=0;int j=0;
        while(i<start.length()||j<target.length()){
            while(i<start.length()&&start[i]=='_')i++;
            while(j<target.length()&&target[j]=='_')j++;
            if(i==start.length()&&j==start.length())break;
            if(start[i]!=target[j])return false;
            if(start[i]=='L')if(i<j)return false;
            if(start[i]=='R')if(j<i)return false;
            i++;
            j++;
        }
        return i==start.length()&&j==start.length();
    }
};