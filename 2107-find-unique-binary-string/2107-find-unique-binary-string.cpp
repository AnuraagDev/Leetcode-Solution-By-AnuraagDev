class Solution {
public:
    int n;
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>se(nums.begin(),nums.end());
        n=nums[0].size();
        return solve(se,"");
    }
    string solve(unordered_set<string>&se,string a){
        if(a.size()==n){
            if(se.find(a)==se.end())return a;
            return "";
        }
        string s=solve(se,a+'0');
        if(s.size()>0)return s;
        return solve(se,a+'1');
    }
};