class Solution {
public:

    string compressedString(string word) {
        string s="";
        char curr=word[0];
        int count=1;
        for(int i=1;i<word.length();i++){
             if(curr==word[i]&&count<9){
                count++;
            }
            else{
                s+=to_string(count);
                s+=curr;
                curr=word[i];
                count=1;
            }
        
        }
        s+=(count+'0');
        s+=curr;
        return s;
    }
};