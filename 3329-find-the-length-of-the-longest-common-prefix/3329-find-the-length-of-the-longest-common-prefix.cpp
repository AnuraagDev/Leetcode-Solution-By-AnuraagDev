class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>set;
        for(auto in:arr1){
            string i=to_string(in);
            string temp="";
            for(int j=0;j<i.length();j++){
                temp+=i[j];
                set.insert(temp);
            }
        }
        int ans=0;
        for(auto in:arr2){
             string i=to_string(in);
            string temp="";
            for(int j=0;j<i.length();j++){
                temp+=i[j];
                if(set.find(temp)!=set.end()){
                    ans=max(ans,j+1);
                }
                else{
                    break;
                }
            }
        }return ans;
    }
};