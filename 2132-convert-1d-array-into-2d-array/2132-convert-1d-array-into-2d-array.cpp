class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
       
        vector<vector<int>>grid(m,vector<int>(n));
        if(original.size()>m*n||original.size()<m*n)return {};
         int i=0,j=0;
        for(auto k:original){
            if(j==n){j=0;i++;}
            if(i==m)break;
            grid[i][j]=k;
            j++;

        }
        return grid;
    }
};