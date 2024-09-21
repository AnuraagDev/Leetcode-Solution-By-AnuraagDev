class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n=mat.size(),m=mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto s=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x_new=s.first+arr[i][0];
                int y_new=s.second+arr[i][1];
                if(x_new>=0&&y_new>=0&&x_new<n&&y_new<m){
                    if(ans[x_new][y_new]>ans[s.first][s.second]+1){
                        ans[x_new][y_new]=ans[s.first][s.second]+1;
                        q.push({x_new,y_new});
                    }
                }
            }
        }return ans;
    }
};