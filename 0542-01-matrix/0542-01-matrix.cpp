class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto d=q.front();
            q.pop();
            int x=d.first;
            int y=d.second;
            for(int i=0;i<4;i++){
                int x_new=x+dir[i][0];
                int y_new=y+dir[i][1];
                if(x_new>=0&&y_new>=0&&x_new<n&&y_new<m){
                    if(ans[x_new][y_new]>ans[x][y]+1){
                        ans[x_new][y_new]=ans[x][y]+1;
                        q.push({x_new,y_new});
                    }
                }
            }
        }return ans;
    }
};