class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        stack<pair<int,int>>st;
        for(auto i=0;i<matrix.size();i++){
            for(auto j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)st.push({i,j});
            }
        }
        while(!st.empty()){
            auto d=st.top();
            st.pop();
            solve(d,matrix);
        }
    }
    void solve(pair<int,int>d,vector<vector<int>>&grid){
        for(auto i=0;i<grid.size();i++){
            grid[i][d.second]=0;
        }
        for(auto j=0;j<grid[0].size();j++){
            grid[d.first][j]=0;
        }
    }
};