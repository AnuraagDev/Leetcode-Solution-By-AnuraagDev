class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]){mp[i]++;
                mp1[j]++;
                q.push({i,j});}
            }
        }
        int count=0;
        while(!q.empty()){
            auto[i,j]=q.front();
            if(mp[i]==1&&mp1[j]==1){
                q.pop();}else{
                    count++;
                    q.pop();
                }

        }
        return count;
    }
};