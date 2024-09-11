class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edge(numCourses);
        vector<int>indegree(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<prerequisites.size();i++){
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<edge.size();i++){
            for(auto j:edge[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }int count=0;
        while(!q.empty()){
            int d=q.front();
            q.pop();
            count++;
            for(auto j:edge[d]){
                indegree[j]--;
                if(!indegree[j]){
                    q.push(j);
                }
            }
        }return count==numCourses;
       
        }
        
};