class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int count=0;
        for(auto &it:mp){
            if(it.second>=2){
                if(it.second%2){
                    count+=1;
                }
                else{
                    count+=2;
                }
            }

            else{
                count+=it.second;
            }
        }
        return count;
    }
};