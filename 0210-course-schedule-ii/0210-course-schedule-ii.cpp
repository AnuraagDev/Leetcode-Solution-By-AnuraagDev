class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>degree(numCourses);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
               degree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<degree.size();i++){
            if(degree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            auto d=q.front();
            ans.push_back(d);
            q.pop();
            for(auto i:adj[d]){
                degree[i]--;
                if(degree[i]==0)q.push(i);
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};