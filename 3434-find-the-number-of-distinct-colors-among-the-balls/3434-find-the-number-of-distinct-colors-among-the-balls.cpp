class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp,mp1;
        vector<int>ans;
        int distinct=0;
        for(auto i:queries){
            int ball=i[0];
            int color=i[1];
            if(mp.find(ball)!=mp.end()){
                int oldColor=mp[ball];
                mp1[oldColor]--;
                if(mp1[oldColor]==0){
                    distinct--;
                }
            }
            mp[ball]=color;
            if(mp1.find(color)==mp1.end() || mp1[color]==0){
                    distinct++;
            }
            mp1[color]++;
            ans.push_back(distinct);
        }
        return ans;
    }
};