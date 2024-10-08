class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>ans;  
        vector<string>map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,"",ans,map,digits);
        return ans;
    }
 void  solve(int i,string temp,vector<string>&ans,vector<string>&map,string &digit){
        if(i==digit.length()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<map[digit[i]-'0'].length();j++){
            temp+=map[digit[i]-'0'][j];
            solve(i+1,temp,ans,map,digit);
            if(!temp.empty()){
                temp.pop_back();
            }
        }
    }

};