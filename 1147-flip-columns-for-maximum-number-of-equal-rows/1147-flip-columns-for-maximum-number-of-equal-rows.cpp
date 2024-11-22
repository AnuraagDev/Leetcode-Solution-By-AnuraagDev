class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       map<vector<int>,int>mp;
        for(auto i:matrix){
            mp[i]++;
            for(auto &j:i){
                j=(!j);
            }
            mp[i]++;
        }
        int maxi=0;
        for(auto i:mp){
            maxi=max(i.second,maxi);
        }
        return maxi;
    }
};