class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
         vector<vector<int>>adj(vals.size());
         for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
         }
         int ans=INT_MIN;
         for(int i=0;i<vals.size();i++){
            vector<int>a;
            for(auto i:adj[i]){
                a.push_back(vals[i]);
            }
            sort(a.begin(),a.end(),greater<int>());
            int an=vals[i];
            ans=max(an,ans);
            int q=0;
            for(int j=0;j<a.size();j++){
                if(a[j]<0)break;
                an+=a[j];
                q++;
                if(q>k)break;
                ans=max(an,ans);
                
            }
         }
         return ans;
        
    }
};