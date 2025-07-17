class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<int>>mp;
        for(int i=0;i<strs.size();i++){
            string dummy=strs[i];
            sort(dummy.begin(),dummy.end());
            mp[dummy].push_back(i);
        }   
        vector<vector<string>>ans;
        for(auto i:mp){
            vector<string>s;
            cout<<i.first<<endl;
            for(auto j:i.second){
                    s.push_back(strs[j]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};