class Solution {
public:
    string clearDigits(string s) {
        vector<int>vec(s.length(),0);
        for(int i=0;i<s.length();i++){
            if(i==0&&isdigit(s[0]))vec[i]=1;
            else{
                if(isdigit(s[i])){
                    vec[i]=1;
                    int j=i;
                    while(j>=0&&vec[j])j--;
                    vec[j]=1;
                }
            }
        }
        for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
        string newi="";
        for(int i=0;i<vec.size();i++){
            if(!vec[i])newi+=s[i];
        }
        return newi;
    }
};