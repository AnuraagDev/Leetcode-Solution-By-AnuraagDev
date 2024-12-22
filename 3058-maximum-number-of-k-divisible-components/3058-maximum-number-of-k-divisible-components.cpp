class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int count=0;
        vector<int>visited(n,0);
        dfs(0,adj,visited,k,values,count);
        return count;
    }
    int dfs(int i,vector<vector<int>>&adj,vector<int>&visited,int k,vector<int>&values,int &count){
        visited[i]=1;
        long long sum=values[i]%k;
        for(auto &j:adj[i]){
            if(!visited[j]){
                sum+=dfs(j,adj,visited,k,values,count);
            }
        }
        if(sum%k==0){count++;return 0;}
        return sum;
    }
    
};