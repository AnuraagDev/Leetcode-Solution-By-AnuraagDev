class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>degree(numCourses,0);
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
               degree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<degree.size();i++){
            if(!degree[i])q.push(i);
        }int count=0;
        while(!q.empty()){
            int d=q.front();
            q.pop();count++;
            for(auto i:adj[d]){
                degree[i]--;
                if(degree[i]==0)q.push(i);
            }
        }return count==numCourses;
        
    }
};